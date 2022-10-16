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

const char MATCHING[] = "Matching";
const char INDEPENDENT[] = "IndSet";

#define MAX   500500
int numNode, numEdge, need;
pair<int, int> edges[MAX];
vector<int> adj[MAX];
bool used[MAX];

void loadGraph(void) {
  scanf("%d%d", &need, &numEdge);
  numNode = 3 * need;

  FOR(i, 1, numNode) adj[i].clear();
  FOR(i, 1, numEdge) {
    int u, v; scanf("%d%d", &u, &v);
    edges[i] = make_pair(u, v);
    adj[u].push_back(i);
    adj[v].push_back(i);
  }
  FOR(i, 1, numNode) used[i] = false;
}

void process(void) {
  set<int> indices;
  FOR(i, 1, numEdge) indices.insert(i);

  vector<int> edgeID;
  while (!indices.empty() && edgeID.size() < need) {
    int id = *indices.begin();
    int u = edges[id].fi, v = edges[id].se;
    assert(!used[u] && !used[v]);

    edgeID.push_back(id);
    used[u] = true; used[v] = true;
    FORE(it, adj[u]) indices.erase(*it);
    FORE(it, adj[v]) indices.erase(*it);
  }

  if (edgeID.size() >= need) {
    printf("%s\n", MATCHING);
    REP(i, need) printf("%d ", edgeID[i]); printf("\n");
    return;
  }

  vector<int> unused;
  FOR(i, 1, numNode) if (!used[i] && unused.size() < need) unused.push_back(i);
  assert(unused.size() == need);
  printf("%s\n", INDEPENDENT);
  FORE(it, unused) printf("%d ", *it); printf("\n");
}

int main(void) {
  int t; scanf("%d", &t);
  REP(love, t) {
    loadGraph();
    process();
  }
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/