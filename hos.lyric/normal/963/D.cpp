#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }


constexpr int A = 26;
int V;
int nxt[100010][A];
int fail[100010];
vector<int> ac[100010];
int newNode() {
  const int u = V++;
  fill(nxt[u], nxt[u] + A, -1);
  ac[u].clear();
  return u;
}
int que[100010], *qb, *qe;
void bfs() {
  qb = qe = que;
  *qe++ = 0;
  for (; qb != qe; ) {
    const int u = *qb++;
    for (int a = 0; a < A; ++a) {
      int &v = nxt[u][a];
      if (v != -1) {
        fail[v] = (u == 0) ? 0 : nxt[fail[u]][a];
        ac[v].insert(ac[v].end(), ac[fail[v]].begin(), ac[fail[v]].end());
        *qe++ = v;
      } else {
        v = (u == 0) ? 0 : nxt[fail[u]][a];
      }
    }
  }
}

constexpr int INF = 1'000'000'000;

char S[100010];
int N;
int K[100010], L[100010];

char M[100010];

vector<int> matches[100010];

int main() {
  for (; ~scanf("%s", S); ) {
    scanf("%d", &N);
    V = 0;
    newNode();
    for (int i = 0; i < N; ++i) {
      scanf("%d%s", &K[i], M);
      L[i] = strlen(M);
      int u = 0;
      for (int j = 0; j < L[i]; ++j) {
        const int a = M[j] - 'a';
        int &v = nxt[u][a];
        if (v == -1) {
          v = newNode();
        }
        u = v;
      }
      ac[u].push_back(i);
    }
    bfs();
    for (int i = 0; i < N; ++i) {
      matches[i].clear();
    }
    {
      int u = 0;
      for (int j = 0; S[j]; ++j) {
        const int a = S[j] - 'a';
        u = nxt[u][a];
        for (const int i : ac[u]) {
          matches[i].push_back(j + 1);
        }
      }
    }
// for(int i=0;i<N;++i){cerr<<i<<": ";pv(matches[i].begin(),matches[i].end());}
    for (int i = 0; i < N; ++i) {
      const int sz = matches[i].size();
      int ans = INF;
      for (int k = 0; k + K[i] - 1 < sz; ++k) {
        chmin(ans, L[i] + matches[i][k + K[i] - 1] - matches[i][k]);
      }
      printf("%d\n", (ans >= INF) ? -1 : ans);
    }
  }
  return 0;
}