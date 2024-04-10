#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 777;
const int MAX = 1e7 + 1000;

bool e[MAXN][MAXN];
bool matched[MAXN];
int dad[MAXN];

int bio[MAXN], cookie;
int a[MAXN];
int n;

bool match(int x) {
  if (x == -1) return true;
  if (bio[x] == cookie) return false;
  bio[x] = cookie;
  REP(i, n)
    if (e[x][i] && match(dad[i])) {
      dad[i] = x;
      return true;
    }
  return false;
}

bool was[MAXN][2];
void dfs(int x, int side) {
  if (was[x][side]) return;
  was[x][side] = true;
  REP(i, n) {
    if (side == 0 && e[x][i]) dfs(i, 1);
    if (side == 1 && dad[x] == i) dfs(i, 0);
  }
}

char* s[MAXN];
int len[MAXN];

struct node {
  node* fail;
  node* parent;
  node* to[2];
  node* finfail;
  int fin;
  bool mark;
  bool e;
  node () { fail = 0; fin = -1; };
} mem[MAX];
node* alloc = mem;

node* insert(node* x, char* s, int i) {
  while (*s) {
    int c = *s - 'a';
    if (x->to[c] == 0) {
      x->to[c] = alloc++;
      x->to[c]->e = c;
      x->to[c]->parent = x;
    }
    x = x->to[c];
    s++;
  }
  x->fin = i;
  return x;
}

void push_links(node *root) {
  static node* Q[MAX];
  int b, e;
  b = e = 0;
  Q[e++] = root;
  while (b < e) {
    node *x = Q[b++];
    
    REP(i, 2)
      if (x->to[i]) Q[e++] = x->to[i];

    if (x == root || x->parent == root) {
      x->fail = root;
      x->finfail = NULL;
    } else {
      x->fail = x->parent->fail;
      while (x->fail != root && !x->fail->to[x->e]) x->fail = x->fail->fail;
      if (x->fail->to[x->e]) x->fail = x->fail->to[x->e];
      if (x->fail->fin != -1) {
        x->finfail = x->fail;
      } else {
        x->finfail = x->fail->finfail;
      }
    }
  }
}

int main(void) {
  scanf("%d", &n);

  static char buf[MAX];
  static node* w[MAXN];
  char* cur = buf;

  node* root = alloc++;
  REP(i, n) {
    scanf("%s", cur);
    s[i] = cur;
    len[i] = strlen(cur);
    cur += len[i] + 1;
    w[i] = insert(root, s[i], i);
  }
  push_links(root);
  
  vector<int> eq[MAXN];
  REP(i, n) REP(j, n)
    if (w[i]->fin == i)
      if (i != j && w[i] == w[j]) {
        eq[i].push_back(j);
      }


  REP(i, n) {
    node *cur = root;

    REP(j, len[i]) {
      while (cur != root && !cur->to[s[i][j]-'a']) cur = cur->fail;
      if (cur->to[s[i][j]-'a']) cur = cur->to[s[i][j]-'a'];

      node *x = cur;
      if (x->fin == -1) x = x->finfail;
      while (x && !e[i][x->fin]) {
        e[i][x->fin] = true;
        x = x->finfail;
      }
    }

    REP(j, n)
      if (e[i][j])
        for (int k: eq[j]) e[i][k] = true;
    e[i][i] = false;
  }

  REP(i, n) dad[i] = -1;

  REP(i, n) {
    cookie++;
    matched[i] = match(i);
  }

  REP(i, n)
    if (!matched[i]) dfs(i, 0);

  bool vc[MAXN];
  REP(i, n) vc[i] = false;
  REP(i, n) {
    if (matched[i] && !was[i][0]) vc[i] = true;
    if (dad[i] != -1 && was[i][1]) vc[i] = true;
  }
  
  vector<int> ans;
  REP(i, n)
    if (!vc[i]) ans.push_back(i);
  
  printf("%d\n", (int)ans.size());
  for (int x: ans) printf("%d ", x+1);
  printf("\n");
  return 0;
}