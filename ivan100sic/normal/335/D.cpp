// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int o[3005][3005], sol[100005];
int c[3005][3005];
int dl[3005][3005], dd[3005][3005], hul[3005][3005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  memset(hul, 255, sizeof hul);

  cin >> n;
  for (int id=0; id<n; id++) {
    int p, q, x, y;
    cin >> p >> q >> x >> y;
    for (int i=p+1; i<=x; i++) {
      for (int j=q+1; j<=y; j++) {
        c[i][j] = 1;
        o[i][j] = id+1;
      }
    }

    for (int j : {q, y}) {
      for (int i=p+1; i<=x; i++) {
        dl[i][j] = 1;
      }
    }

    for (int i : {p, x}) {
      for (int j=q+1; j<=y; j++) {
        dd[i][j] = 1;
      }
    }
  }

  for (int i=0; i<=3001; i++) {
    for (int j=0; j<=3001; j++) {
      if (i && dl[i][j]) dl[i][j] += dl[i-1][j];
      if (j && dd[i][j]) dd[i][j] += dd[i][j-1];

      if (dl[i][j]) {
        hul[i][j] = j;
      } else if (dd[i][j]) {
        hul[i][j] = hul[i][j-1];
      }

      if (c[i][j]) {
        c[i][j] = 1 + min({c[i-1][j], c[i][j-1], c[i-1][j-1]});
      }
    }
  }

  for (int i=1; i<=3001; i++) {
    for (int j=1; j<=3001; j++) {
      int w = min({c[i][j], dl[i][j], dd[i][j]});
      if (!w) continue;

      int q = hul[i][j-1];

      while (q != -1 && j-q <= w) {
        int a = j-q;
        if (dl[i][j-a] >= a && dd[i-a][j] >= a) {
          cout << "YES ";
          // cerr << "params = " << i << ' ' << j << ' ' << a << '\n';

          for (int f=i-a+1; f<=i; f++) {
            for (int g=j-a+1; g<=j; g++) {
              sol[o[f][g]] = 1;
            }
          }

          vector<int> ans;
          for (int i=1; i<=n; i++) {
            if (sol[i]) {
              ans.push_back(i);
            }
          }

          cout << ans.size() << '\n';
          for (int x : ans) {
            cout << x << ' ';
          }
          cout << '\n';

          return 0;
        }

        if (q) {
          q = hul[i][q-1];
        } else {
          q = -1;
        }
      }
    }
  }

  cout << "NO\n";

}