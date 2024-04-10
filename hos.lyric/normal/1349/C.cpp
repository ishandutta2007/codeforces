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

constexpr int DX[] = {+1, 0, -1, 0};
constexpr int DY[] = {0, +1, 0, -1};

int M, N, T;
char A[1010][1010];

int que[2000010], *qb, *qe;
int dist[1010][1010];
int col[1010][1010];

int main() {
  for (; ~scanf("%d%d%d", &M, &N, &T); ) {
    for (int x = 0; x < M; ++x) {
      scanf("%s", A[x]);
    }
    
    qb = qe = que;
    for (int x = 0; x < M; ++x) for (int y = 0; y < N; ++y) {
      dist[x][y] = -1;
      col[x][y] = -1;
    }
    for (int x = 0; x < M; ++x) for (int y = 0; y < N; ++y) {
      bool isol = true;
      for (int dir = 0; dir < 4; ++dir) {
        const int xx = x + DX[dir];
        const int yy = y + DY[dir];
        if (0 <= xx && xx < M && 0 <= yy && yy < N) {
          isol = isol && (A[x][y] != A[xx][yy]);
        }
      }
      if (!isol) {
        dist[x][y] = 0;
        col[x][y] = A[x][y] - '0';
        *qe++ = x;
        *qe++ = y;
      }
    }
    for (; qb != qe; ) {
      const int x = *qb++;
      const int y = *qb++;
      for (int dir = 0; dir < 4; ++dir) {
        const int xx = x + DX[dir];
        const int yy = y + DY[dir];
        if (0 <= xx && xx < M && 0 <= yy && yy < N) {
          if (dist[xx][yy] == -1) {
            dist[xx][yy] = dist[x][y] + 1;
            col[xx][yy] = col[x][y];
            *qe++ = xx;
            *qe++ = yy;
          }
        }
      }
    }
// cerr<<"dist = "<<endl;for(int x=0;x<M;++x)pv(dist[x],dist[x]+N);
// cerr<<"col = "<<endl;for(int x=0;x<M;++x)pv(col[x],col[x]+N);
    
    for (int t = 0; t < T; ++t) {
      int x, y;
      Int p;
      scanf("%d%d%lld", &x, &y, &p);
      --x;
      --y;
      int ans;
      if (dist[x][y] != -1 && dist[x][y] <= p) {
        ans = col[x][y];
        ans ^= (p & 1);
      } else {
        ans = A[x][y] - '0';
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}