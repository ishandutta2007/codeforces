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


namespace MF {
	const int LIM_N = 1'000'010;
	const int LIM_M = 1'000'010;
	typedef int wint;
	const wint wEPS = 0;
	const wint wINF = 1001001001;
	int n, m, ptr[LIM_N], nxt[LIM_M * 2], zu[LIM_M * 2];
	wint capa[LIM_M * 2], tof;
	int lev[LIM_N], see[LIM_N], que[LIM_N], *qb, *qe;
	void init(int _n) {
		n = _n; m = 0; fill(ptr, ptr + n, -1);
	}
	void ae(int u, int v, wint w0, wint w1 = 0) {
		nxt[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w0; ++m;
		nxt[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = w1; ++m;
	}
	wint augment(int src, int ink, wint flo) {
		if (src == ink) return flo;
		for (int &i = see[src]; ~i; i = nxt[i]) if (capa[i] > wEPS && lev[src] < lev[zu[i]]) {
			const wint f = augment(zu[i], ink, min(flo, capa[i]));
			if (f > wEPS) {
				capa[i] -= f; capa[i ^ 1] += f; return f;
			}
		}
		return 0;
	}
	bool solve(int src, int ink, wint flo = wINF) {
		for (tof = 0; tof + wEPS < flo; ) {
			qb = qe = que; fill(lev, lev + n, -1);
			for (lev[*qe++ = src] = 0, see[src] = ptr[src]; qb != qe; ) {
				const int u = *qb++;
				for (int i = ptr[u]; ~i; i = nxt[i]) if (capa[i] > wEPS) {
					const int v = zu[i];
					if (lev[v] == -1) {
						lev[*qe++ = v] = lev[u] + 1; see[v] = ptr[v];
						if (v == ink) goto au;
					}
				}
			}
			return false;
		au:	for (wint f; (f = augment(src, ink, flo - tof)) > wEPS; tof += f);
		}
		return true;
	}
  
  bool vis[LIM_N];
  void dfs(int u) {
    if (!vis[u]) {
      vis[u] = true;
      for (int i = ptr[u]; ~i; i = nxt[i]) {
        if (capa[i] > wEPS) {
          dfs(zu[i]);
        }
      }
    }
  }
}


constexpr int DX[4] = {+1, 0, -1, 0};
constexpr int DY[4] = {0, +1, 0, -1};

constexpr int MAX_N = 210;

using Pt = pair<int, int>;

int N;
Int A[MAX_N][MAX_N];

int asLen;
Int as[MAX_N * MAX_N];
int ids[MAX_N][MAX_N];
int cut[MAX_N][MAX_N];

void solve(int iL, int iR, const vector<Pt> &ps) {
// cerr<<"solve "<<iL<<" "<<iR<<"; ";pv(ps.begin(),ps.end());
  if (iR - iL == 1) {
    for (const auto &p : ps) {
      cut[p.first][p.second] = iL;
    }
    return;
  }
  if (ps.empty()) {
    return;
  }
  const int iMid = (iL + iR) / 2;
  const int psLen = ps.size();
  MF::init(psLen + 2);
  for (int u = 0; u < psLen; ++u) {
    ids[ps[u].first][ps[u].second] = u;
  }
  for (int u = 0; u < psLen; ++u) {
    for (int dir = 0; dir < 4; ++dir) {
      const int xx = ps[u].first + DX[dir];
      const int yy = ps[u].second + DY[dir];
      if (A[xx][yy] >= 0) {
        const int v = ids[xx][yy];
        if (v == -1) {
          if (A[xx][yy] < as[iMid]) {
            MF::ae(psLen, u, 1);
          } else {
            MF::ae(u, psLen + 1, 1);
          }
        } else {
          if (u < v) {
            MF::ae(u, v, 1, 1);
          }
        }
      }
    }
  }
  for (int u = 0; u < psLen; ++u) {
    ids[ps[u].first][ps[u].second] = -1;
  }
  
  MF::solve(psLen, psLen + 1);
  fill(MF::vis, MF::vis + MF::n, false);
  MF::dfs(psLen);
  vector<Pt> psL, psR;
  for (int u = 0; u < psLen; ++u) {
    (MF::vis[u] ? psL : psR).push_back(ps[u]);
  }
  
  for (const auto &p : psR) A[p.first][p.second] = as[iMid];
  solve(iL, iMid, psL);
  for (const auto &p : psR) A[p.first][p.second] = 0;
  for (const auto &p : psL) A[p.first][p.second] = as[iMid - 1];
  solve(iMid, iR, psR);
  for (const auto &p : psL) A[p.first][p.second] = 0;
}

int main() {
  for (; ~scanf("%d", &N); ) {
    for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y) {
      scanf("%lld", &A[x][y]);
    }
    
    asLen = 0;
    for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y) {
      if (A[x][y] >= 1) {
        as[asLen++] = A[x][y];
      }
    }
    sort(as, as + asLen);
    asLen = unique(as, as + asLen) - as;
// cerr<<"as = ";pv(as,as+asLen);
    
    for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y) {
      ids[x][y] = -1;
      cut[x][y] = -1;
    }
    
    vector<Pt> ps;
    for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y) {
      if (A[x][y] == 0) {
        ps.emplace_back(x, y);
      }
    }
    
    solve(0, asLen, ps);
    for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y) {
      if (A[x][y] == 0) {
        assert(cut[x][y] != -1);
        A[x][y] = as[cut[x][y]];
      }
    }
    
    Int ans = 0;
    for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y) {
      if (A[x][y] >= 1) {
        for (int dir = 0; dir < 4; ++dir) {
          const int xx = x + DX[dir];
          const int yy = y + DY[dir];
          if (0 <= xx && xx < N && 0 <= yy && yy < N && A[xx][yy] >= 1) {
            if (Pt(x, y) < Pt(xx, yy)) {
              ans += abs(A[x][y] - A[xx][yy]);
            }
          }
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}