#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

typedef vector<vector<int>> Gate;

vector<int> solve(int w, vector<int>& cnt, vector<Gate> gates) {
  int M = 1 << (2 * w);
  vector<int> cntp(M);
  for (int i = 0; i < (1 << w); ++i) {
    for (int j = 0; j <= i; ++j) {
      int p = 0;
      for (int k = 0; k < w; ++k) {
        p = p * 4 + ((i >> k) & 1) + ((j >> k) & 1);
      }
      if (i == j) {
        cntp[p] += cnt[i] * cnt[i];
      } else {
        cntp[p] += cnt[i] * cnt[j] * 2;
      }
    }
  }

  int t = 0;
  for (int i = 0; i < M; ++i) {
    t += cntp[i];
  }

  vector<int> f = cntp;
  for (int i = 0; i < w; ++i) {
    for (int j = M - 1; j >= 0; --j) {
      int b = (j >> (2 * i)) & 3;
      f[j + ((3 - b) << (2 * i))] += f[j];
    }
  }

  vector<int> ret;
  for (Gate& g : gates) {
    int fixed = 0;
    vector<pair<int, int>> unfixed;
    for (int i = 0; i < w; ++i) {
      if (g[i].size() == 1) {
        fixed += g[i][0] << (2 * i);
      } else {
        fixed += 3 << (2 * i);
        unfixed.push_back({i, 3 - g[i][0] - g[i][1]});
      }
    }

    int k = unfixed.size();
    int l = k / 2;
    int r = k - l;

    vector<int> lmask(1 << l), lsgn(1 << l);
    for (int s = 0; s < (1 << l); ++s) {
      int sgn = 1, mask = 0;
      for (int i = 0; i < l; ++i) {
        if (s & (1 << i)) {
          sgn *= -1;
          mask += (3 - unfixed[i].second) << (2 * unfixed[i].first);
        }
      }
      lmask[s] = mask;
      lsgn[s] = sgn;
    }

    vector<int> rmask(1 << r), rsgn(1 << r);
    for (int s = 0; s < (1 << r); ++s) {
      int sgn = 1, mask = 0;
      for (int i = 0; i < r; ++i) {
        if (s & (1 << i)) {
          sgn *= -1;
          mask += (3 - unfixed[l + i].second) << (2 * unfixed[l + i].first);
        }
      }
      rmask[s] = mask;
      rsgn[s] = sgn;
    }

    int count = 0;
    for (int s = 0; s < (1 << l); ++s) {
      for (int p = 0; p < (1 << r); ++p) {
        count += lsgn[s] * rsgn[p] * f[fixed - lmask[s] - rmask[p]];
      }
    }
    ret.push_back(count);
  }
  return ret;
}

int main(void) {
  ios_base::sync_with_stdio(false);

  int w, N, M;
  cin >> w >> N >> M;

  vector<int> cnt(1 << w);
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    cnt[x]++;
  }

  vector<Gate> gates;
  for (int i = 0; i < M; ++i) {
    string g;
    cin >> g;

    Gate gate;
    assert((int)g.size() == w);

    for (int j = 0; j < w; ++j) {
      vector<int> b;
      if (g[j] == 'A' || g[j] == 'O' || g[j] == 'X') {
        b.push_back(0);
      }
      if (g[j] == 'A' || g[j] == 'o' || g[j] == 'x') {
        b.push_back(1);
      }
      if (g[j] == 'X' || g[j] == 'a' || g[j] == 'o') {
        b.push_back(2);
      }
      gate.push_back(b);
      assert((int)b.size() >= 1 && (int)b.size() <= 2);
    }

    gates.push_back(gate);
  }

  vector<int> ret = solve(w, cnt, gates);
  for (int x : ret) {
    cout << x << "\n";
  }
  return 0;
}