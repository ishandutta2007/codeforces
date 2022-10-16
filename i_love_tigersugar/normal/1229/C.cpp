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

struct Edge {
  int from, to;

  Edge(int _from = 0, int _to = 0) {
    from = _from; to = _to;
  }

  void rev(void) {
    swap(from, to);
  }

  int other(int x) const {
    assert(from == x || to == x);
    return from ^ to ^ x;
  }
};

#define MAX   100100
queue<int> adj[MAX];
Edge edges[MAX];
int value[MAX], inDeg[MAX], outDeg[MAX];
int numNode, numEdge, numQuery;
long long answer;

void loadGraph(void) {
  scanf("%d%d", &numNode, &numEdge);
  FOR(i, 1, numEdge) {
    int u, v; scanf("%d%d", &u, &v);
    if (u > v) swap(u, v);
    edges[i] = Edge(u, v);
    adj[u].push(i);
    outDeg[u]++; inDeg[v]++;
  }

  FOR(i, 1, numNode) answer += 1LL * inDeg[i] * outDeg[i];
  FOR(i, 1, numNode) value[i] = i;
  cout << answer << "\n";
}

void revEdge(int id) {
  if (value[edges[id].from] < value[edges[id].to]) return;
  int from = edges[id].from, to = edges[id].to;
  int oldValue = inDeg[from] + outDeg[to]; outDeg[from]--; inDeg[to]--;
  swap(from, to);
  outDeg[from]++; inDeg[to]++;
  int newValue = inDeg[from] + outDeg[to];
  edges[id] = Edge(from, to);
  adj[from].push(id);
  answer += newValue - oldValue;
}

void updateNode(int u) {
  while (!adj[u].empty()) {
    int id = adj[u].front(); adj[u].pop();
    revEdge(id);
  }
}

void process(void) {
  scanf("%d", &numQuery);
  FOR(i, 1, numQuery) {
    int u; scanf("%d", &u);
    value[u] = numNode + i;
    updateNode(u);
    cout << answer << "\n";
  }
}

int main(void) {
  loadGraph();
  process();
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/