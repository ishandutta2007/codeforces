#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define FAIL { puts("NO"), exit(EXIT_SUCCESS); }

const int N = 2000 + 10;
const int EMPTY = 0, SUB = 1, FULL = 2;
const int LEFT = 1, RIGHT = 2, BLOCK = 3;

int n;
char a[N][N];

struct node_t {
  std::vector<node_t*> next;
  char type;
  int id;
  bool tag, flag;
  node_t(char _c = 'S'): type(_c), tag(false), flag(false) { next.clear(); }
  void reverse() {
    flag ^= 1;
    std::reverse(next.begin(), next.end());
  }
  void release() {
    if (!flag) return;
    for (std::vector<node_t*>::iterator it = next.begin(); it != next.end(); ++it) (*it)->reverse();
    flag = false;
  }
  void toggle() {
    if (!tag) FAIL;
    tag = false;
    reverse();
  }
  void print();
} *root = new node_t('P'), pool[N];

void node_t::print() {
  release();
  printf("%p %c:", this, type);
  if (type == 'S') {
    printf("%ld\n", this - pool);
    return;
  }
  for (std::vector<node_t*>::iterator it = next.begin(); it != next.end(); ++it) printf("%p ", *it);
  putchar('\n');
  for (std::vector<node_t*>::iterator it = next.begin(); it != next.end(); ++it) (*it)->print();
}

std::vector<bool> state(N);

void DFS(node_t *u) {
  u->release();
  if (u->type == 'S') {
    u->id = (state[u - pool] ? FULL : EMPTY);
    return;
  }
  u->id = 0;
  int a = 0, b = 0;
  for (std::vector<node_t*>::iterator it = u->next.begin(); it != u->next.end(); ++it) {
    node_t *v = *it;
    DFS(v);
    a += (v->id == EMPTY);
    b += (v->id == FULL);
  }
  if (a == u->next.size())
    u->id = EMPTY;
  else if (b == u->next.size())
    u->id = FULL;
  else
    u->id = SUB;
}

node_t *Solve(node_t *u, int dir) {
  u->release();
  if (u->id != SUB) return u;
  std::vector<node_t*> set[3];
  for (std::vector<node_t*>::iterator it = u->next.begin(); it != u->next.end(); ++it) {
    node_t *v = *it;
    set[v->id].push_back(v);
  }
  if (set[SUB].size() > 2) FAIL;
  if (set[SUB].size() == 2 && dir != BLOCK) FAIL;
  if (u->type == 'P') {
    if (set[FULL].empty() && set[SUB].size() == 1 && dir == BLOCK) {
      for (std::vector<node_t*>::iterator it = u->next.begin(); it != u->next.end(); ++it) {
        node_t *&v = *it;
        if (v->id == SUB) {
          v = Solve(v, BLOCK);
          break;
        }
      }
      return u;
    }
    node_t *x;
    if (set[FULL].empty()) {
      x = NULL;
    } else if (set[FULL].size() == 1) {
      x = set[FULL][0];
    } else {
      x = new node_t('P');
      x->next = set[FULL];
    }
    std::vector<node_t*> temp;
    if (dir != LEFT && !set[SUB].empty()) temp.push_back(Solve(set[SUB][0], RIGHT));
    if (x) temp.push_back(x);
    if (dir != RIGHT && set[SUB].size() > (dir == BLOCK ? 1 : 0))
      temp.push_back(Solve(set[SUB].back(), LEFT));
    node_t *z = NULL;
    if (temp.size() == 1) {
      z = temp[0]; 
    } else {
      z = new node_t('Q');
      z->next = temp;
      z->tag = (dir == BLOCK);
    }
    if (set[EMPTY].empty()) {
      u = z;
    } else {
      if (dir == BLOCK) {
        u->next = set[EMPTY];
        u->next.push_back(z);
      } else {
        node_t *y = NULL;
        if (set[EMPTY].size() == 1) {
          y = set[EMPTY][0];
        } else {
          y = new node_t('P');
          y->next = set[EMPTY];
        }
        u->type = 'Q';
        u->tag = false;
        u->next.clear();
        if (dir == RIGHT) std::swap(y, z);
        u->next.push_back(z);
        u->next.push_back(y);
      }
    }
    return u;
  } else {
    if (dir == LEFT && !(u->next[0]->id == FULL || (u->next[0]->id == SUB && u->next.back()->id != FULL))) u->toggle();
    if (dir == RIGHT && !(u->next.back()->id == FULL || (u->next.back()->id == SUB && u->next[0]->id != FULL))) u->toggle();
    u->release();
    bool flag = false;
    int last = -1;
    for (std::vector<node_t*>::iterator it = u->next.begin(); it < u->next.end(); ++it) {
      node_t *v = *it;
      if (~last) {
        if (dir == LEFT && v->id > last) FAIL;
        if (dir == RIGHT && v->id < last) FAIL;
        if (v->id == EMPTY && last != EMPTY) flag = true;
        if (flag && v->id != EMPTY && last != EMPTY) FAIL;
      }
      last = v->id;
    }
    int cnt = 0;
    for (std::vector<node_t*>::iterator it = u->next.begin(); it != u->next.end(); ++it) {
      node_t *&v = *it;
      cnt += (v->id != EMPTY);
      if (v->id == SUB) {
        if (dir == LEFT) {
          v = Solve(v, LEFT);
        } else if (dir == RIGHT) {
          v = Solve(v, RIGHT);
        } else {
          if (set[FULL].empty() && set[SUB].size() == 1)
            v = Solve(v, BLOCK);
          else
            v = Solve(v, (cnt > 1) ? LEFT : RIGHT);
        }
      }
    }
    return u;
  }
} 

std::vector<int> ans;

void Inorder(node_t *u) {
  if (u->type == 'S') {
    ans.push_back(u - pool);
    return;
  }
  u->release();
  for (std::vector<node_t*>::iterator it = u->next.begin(); it < u->next.end(); ++it) Inorder(*it);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %s", a[i]);
    root->next.push_back(pool + i);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) state[j] = (a[i][j] == '1');
    DFS(root);
    root = Solve(root, BLOCK);
  }
  ans.clear();
  Inorder(root);
  puts("YES");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) putchar(a[i][ans[j]]);
    putchar('\n');
  }
  return 0;
}