#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

struct Node {
  Node *left, *right;
  long long sum;

  Node() {
    left = right = NULL;
    sum = 0;
  }
  Node(Node *p) {
    left = p->left; right = p->right;
    sum = p->sum;
  }

};

#define MAX_NODE   MASK(23)
int nodeCount;
Node nodes[MAX_NODE];
Node* createNode(Node *root = NULL) {
  Node *p = &nodes[nodeCount];
  nodeCount = (nodeCount + 1) & (MAX_NODE - 1);
  p->left = root ? root->left : NULL;
  p->right = root ? root->right : NULL;
  p->sum = root ? root->sum : 0;
  return p;
}

class SegmentTree {
private:

  Node *root;
  int n;

  void build(Node *&p, int l, int r) {
    if (l > r) return;
    p = createNode();
    if (l == r) return;
    int m = (l + r) >> 1;
    build(p->left, l, m);
    build(p->right, m + 1, r);
  }

  long long getSum(Node *p, int l, int r, int u, int v) const {
    if (l > v || r < u || l > r || v < u) return 0;
    if (u <= l && r <= v) return p->sum;
    int m = (l + r) >> 1;
    long long L = getSum(p->left, l, m, u, v);
    long long R = getSum(p->right, m + 1, r, u, v);
    return L + R;
  }

public:
  SegmentTree(int n = 0) {
    root = NULL;
    this->n = n;
    if (n > 0) build(root, 1, n);
  }

  void update(int pos) {
    root = createNode(root);
    Node *p = root;
    int l = 1, r = n;
    while (true) {
      p->sum += pos;
      if (l == r) return;
      int m = (l + r) >> 1;
      if (pos > m) {
        p->right = createNode(p->right);
        p = p->right;
        l = m + 1;
      } else {
        p->left = createNode(p->left);
        p = p->left;
        r = m;
      }
    }
  }

  long long getSum(int l, int r) const {
    return getSum(root, 1, n, l, r);
  }
};

#define MAX   100100
int value[MAX], prev[MAX], next[MAX];
int oldPrev[MAX], oldNext[MAX], indices[MAX];
vector<int> prevChanges, nextChanges;
set<int> pos[MAX];
SegmentTree sumPrev[MAX], sumNext[MAX];
int n, q;

void init(void) {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) scanf("%d", &value[i]);
  FOR(i, 1, n) indices[i] = i;

  FOR(i, 1, n) {
    pos[i].insert(0);
    pos[i].insert(n + 1);
  }
  FOR(i, 1, n) {
    pos[value[i]].insert(i);
  }
  FOR(i, 1, n) {
    __typeof(pos[value[i]].begin()) it = pos[value[i]].find(i);
    it--; prev[i] = *it; it++;
    it++; next[i] = *it; it--;
  }
}

bool compPrev(const int &x, const int &y) {
  return prev[x] < prev[y];
}
bool compNext(const int &x, const int &y) {
  return next[x] > next[y];
}

void buildData(void) {
  sort(indices + 1, indices + n + 1, compPrev);
  sumPrev[0] = SegmentTree(n);
  int j = 1;
  FOR(i, 0, n) {
    while (j <= n && prev[indices[j]] <= i) {
      sumPrev[i].update(indices[j]);
      j++;
    }
    sumPrev[i + 1] = sumPrev[i];
  }

  sort(indices + 1, indices + n + 1, compNext);
  sumNext[n + 1] = SegmentTree(n);
  j = 1;
  FORD(i, n + 1, 1) {
    while (j <= n && next[indices[j]] >= i) {
      sumNext[i].update(indices[j]);
      j++;
    }
    sumNext[i - 1] = sumNext[i];
  }

  prevChanges.clear();
  nextChanges.clear();
  FOR(i, 1, n) {
    oldPrev[i] = prev[i];
    oldNext[i] = next[i];
  }
}

#define IN_RANGE(x) (1 <= (x) && (x) <= n)
#define PREV   0
#define NEXT   1
void updatePos(int x, int val) {
  assert(x != val);
  int mode = x < val ? NEXT : PREV;
  if (mode == PREV) {
    if (IN_RANGE(x)) prevChanges.push_back(x);
    prev[x] = val;
  } else {
    if (IN_RANGE(x)) nextChanges.push_back(x);
    next[x] = val;
  }
}

void removeValue(int x, int val) {
  int L = prev[x], R = next[x];
  assert(pos[val].erase(x));
  updatePos(L, R);
  updatePos(R, L);
}
void insertValue(int x, int val) {
  assert(pos[val].insert(x).se);
  __typeof(pos[val].begin()) it = pos[val].find(x);
  it--; int L = *it; it++;
  it++; int R = *it; it--;
  updatePos(L, x);
  updatePos(R, x);
  updatePos(x, L);
  updatePos(x, R);
}
void updateQuery(int x, int val) {
  removeValue(x, value[x]);
  value[x] = val;
  insertValue(x, value[x]);
}

bool marked[MAX];
long long getPrevSum(int l, int r) {
  long long sum = sumPrev[l - 1].getSum(l, r);
  FORE(it, prevChanges) if (l <= *it && *it <= r && !marked[*it]) {
    int before = oldPrev[*it] < l;
    int after = prev[*it] < l;
    sum += *it * (after - before);
    marked[*it] = true;
  }
  FORE(it, prevChanges) marked[*it] = false;
  return sum;
}
long long getNextSum(int l, int r) {
  long long sum = sumNext[r + 1].getSum(l, r);
  FORE(it, nextChanges) if (l <= *it && *it <= r && !marked[*it]) {
    int before = oldNext[*it] > r;
    int after = next[*it] > r;
    sum += *it * (after - before);
    marked[*it] = true;
  }
  FORE(it, nextChanges) marked[*it] = false;
  return sum;
}
long long query(int l, int r) {
  return getNextSum(l, r) - getPrevSum(l, r);
}

#ifdef ONLINE_JUDGE
  #define SIZE   1000
#else
  #define SIZE   2
#endif
void process(void) {
  int numUpdate = 0;
  buildData();
  FOR(i, 1, q) {
    int type, l, r; scanf("%d%d%d", &type, &l, &r);
    if (type == 1) {
      numUpdate++;
      updateQuery(l, r);
      if (numUpdate % SIZE == 0) buildData();
    } else cout << query(l, r) << "\n";
  }
}

int main(void) {
  init();
  process();
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/