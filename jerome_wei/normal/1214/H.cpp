#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
 
/* Author: Van Hanh Pham */
 
/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/
 
const int INF = (int)1e9 + 7;
 
const string YES = "YES";
const string NO = "NO";
 
#define MAX   200200
int numNode, numColor;
vector<int> adj[MAX];
vector<int> path;
int color[MAX], par[MAX], maxDepth[MAX];
int inPath[MAX];
 
void loadTree(void) {
  scanf("%d%d", &numNode, &numColor);
  REP(love, numNode - 1) {
    int u, v; scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}
 
void answerYes(void) {
  cout << YES << endl;
  FOR(i, 1, numNode) printf("%d ", color[i] + 1); printf("\n");
  exit(EXIT_SUCCESS);
}
 
void answerNo(void) {
  cout << NO << endl;
  exit(EXIT_SUCCESS);
}
 
void bfsKEqualTwo(void) {
  queue<int> q;
  q.push(1); color[1] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    FORE(it, adj[u]) if (*it != par[u]) {
      int v = *it;
      color[v] = color[u] ^ 1;
      par[v] = u;
      q.push(v);
    }
  }
 
  answerYes();
}
 
int bfsFarthest(int start) {
  memset(par, -1, sizeof par);
  queue<int> q;
  par[start] = 0; q.push(start);
 
  int last = start;
  while (!q.empty()) {
    int u = q.front(); q.pop(); last = u;
    FORE(it, adj[u]) if (*it != par[u]) {
      int v = *it;
      par[v] = u;
      q.push(v);
    }
  }
 
  return last;
}
 
void dfsDepth(int u, int par) {
  maxDepth[u] = 0;
  vector<int> children;
 
  FORE(it, adj[u]) if (inPath[*it] < 0 && *it != par) {
    int v = *it;
    dfsDepth(v, u);
    maximize(maxDepth[u], maxDepth[v] + 1);
    children.push_back(maxDepth[v]);
  }
 
  if (children.size() > 1) {
    sort(ALL(children), greater<int>());
    int longest = children[0] + children[1] + 3;
    if (longest >= numColor) answerNo();
  }
}
 
void check(const vector<pair<int, int>> &v) {
  int tmp = -INF;
  FORE(it, v) {
    if (it->fi + it->se + tmp + 1 >= numColor) answerNo();
    maximize(tmp, it->se - it->fi);
  }
}
 
void dfsFill(int u, int par, int delta, int col) {
  color[u] = col;
  FORE(it, adj[u]) if (inPath[*it] < 0 && *it != par) {
    int v = *it;
    int newColor = (col + delta + numColor) % numColor;
    dfsFill(v, u, delta, newColor);
  }
}
 
void process(void) {
  // build longest path
  int node = bfsFarthest(bfsFarthest(1));
  memset(inPath, -1, sizeof inPath);
  for (; node > 0; node = par[node]) {
    inPath[node] = path.size();
    path.push_back(node);
  }
 
  if (path.size() < numColor) {
    FOR(i, 1, numNode) color[i] = 0;
    answerYes();
  }
 
  vector<pair<int, int>> left, right;
 
  int pathLength = path.size() - 1;
  REP(i, pathLength + 1) {
    int root = path[i];
    dfsDepth(root, -1);
    int distLeft = i;
    int distRight = pathLength - i;
    int distDown = maxDepth[root];
 
    if (distDown == 0 || distDown + max(distLeft, distRight) + 1 < numColor) continue;
    if (distDown > 0 && distDown + distLeft + 1 >= numColor && distDown + distRight + 1 >= numColor) answerNo();
    if (distLeft < distRight) left.push_back(make_pair(i, distDown));
    else right.push_back(make_pair(i, distDown));
  }
 
  check(left);
  check(right);
 
  REP(i, pathLength + 1) {
    int root = path[i];
    int distLeft = i;
    int distRight = pathLength - i;
 
    color[root] = i % numColor;
    if (maxDepth[root] > 0) dfsFill(root, -1, distLeft > distRight ? 1 : -1, color[root]);
  }
 
  answerYes();
}
 
int main(void) {
  loadTree();
  if (numColor == 2) bfsKEqualTwo();
  process();
  return 0;
}