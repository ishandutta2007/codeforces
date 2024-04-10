#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 55;

vector<int> E[MAX];
vector<double> f[MAX];
double choose[MAX][MAX];

void dfs(int x, int dad) {
  f[x] = {1.0};

  for (int y : E[x]) {
    if (y != dad) {
      dfs(y, x);

      vector<double> fy(f[y].size() + 1);
      for (int k = 0; k < (int)fy.size(); ++k) {
        for (int i = 0; i < (int)fy.size() - 1; ++i) {
          if (i < k) {
            fy[k] += f[y][k - 1];
          } else {
            fy[k] += f[y][i] * 0.5;
          }
        }
        fy[k] /= (int)fy.size() - 1;
      }

      int nsz = fy.size() + f[x].size() - 1;
      vector<double> nf(nsz);
      for (int k = 0; k < nsz; ++k) {
        for (int i = 0; i < (int)fy.size() && i <= k; ++i) {
          int j = k - i;
          if (j >= (int)f[x].size()) continue;

          nf[k] += choose[k][i] * choose[nsz - 1 - k][(int)fy.size() - 1 - i] *
                   fy[i] * f[x][j];
        }
        nf[k] /= choose[nsz - 1][(int)fy.size() - 1];
      }

      f[x] = nf;
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  for (int i = 0; i <= N; ++i) {
    choose[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
    }
  }

  REP(i, N - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  REP(x, N) {
    dfs(x, -1);

    double ret = f[x][0];
    cout << setprecision(10) << ret << "\n";
  }
  return 0;
}