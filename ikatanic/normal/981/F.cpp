#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

vector<llint> A, B;
vector<pair<llint, int>> C;
vector<int> nxtB, prvB;
int N;
llint L;

bool can(llint R) {
  int x = 0, y = 2*N;

  vector<int> p(N+1, 0);

  for (int i = 2*N; i < 4*N; ++i) {
    y = max(y, i);
    while (C[i].first - C[x].first > R) x++;
    while (y < 6*N && C[y].first - C[i].first <= R) y++;

    if (C[i].second > 0) {
      if (y - x >= 2*N) {
        p[0]++;
        p[N]--;
        continue;
      }

      int xi = nxtB[x];
      int yi = prvB[y-1];

      if (xi >= y || xi == -1) return false;

      assert(yi != -1 && yi >= x);
      assert(xi <= yi);

      int xb = (-C[xi].second - C[i].second + N) % N;
      int yb = (-C[yi].second - C[i].second + N) % N;

      if (xb <= yb) {
        p[xb]++;
        p[yb+1]--;
      } else {
        p[xb]++;
        p[N]--;
        p[0]++;
        p[yb+1]--;
      }
    }
  }

  int cnt = 0;
  REP(i, N) {
    cnt += p[i];
    if (cnt == N) return true;
  }

  return false;
}

int main(void) {
  scanf("%d %lld", &N, &L);
  A.resize(N);
  B.resize(N);
  REP(i, N) scanf("%lld", &A[i]);
  REP(i, N) scanf("%lld", &B[i]);

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  vector<pair<llint, int>> V;
  REP(i, N) V.push_back({A[i], i+1});
  REP(i, N) V.push_back({B[i], -(i+1)});

  sort(V.begin(), V.end(), [&] (const pair<int, int>& a, const pair<int, int>& b) {
      if (a.first != b.first) return a.first < b.first;
      return abs(a.second) < abs(b.second);
    });

  C.resize(6*N);
  REP(i, 2*N) {
    C[i] = V[i];
    C[i].first -= L;
  }
  REP(i, 2*N) {
    C[2*N+i] = V[i];
  }
  REP(i, 2*N) {
    C[4*N+i] = V[i];
    C[4*N+i].first += L;
  }


  nxtB.resize(6*N);
  int nxt = -1;
  for (int i = 6*N - 1; i >= 0; --i) {
    if (C[i].second < 0) nxt = i;
    nxtB[i] = nxt;
  }

  prvB.resize(6*N);
  int prv = -1;
  for (int i = 0; i < 6*N; ++i) {
    if (C[i].second < 0) prv = i;
    prvB[i] = prv;
  }


  llint lo = 0, hi = L;
  while (lo < hi) {
    llint mid = (lo + hi) / 2;
    if (can(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  printf("%lld\n", lo);
  return 0;
}