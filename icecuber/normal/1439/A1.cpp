#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (string&s : a) cin >> s;
    vector<array<int,6>> ans;
    auto add =
      [&](int r0, int c0, int r1, int c1, int r2, int c2) {
        a[r0][c0] ^= 1;
        a[r1][c1] ^= 1;
        a[r2][c2] ^= 1;
        ans.push_back({r0+1,c0+1, r1+1,c1+1, r2+1,c2+1});
      };
    for (int i = 0; i+2 <= h; i += 2) {
      for (int j = 0; j+2 <= w; j += 2) {
        int i1 = i+3 == h ? h : i+2;
        int j1 = j+3 == w ? w : j+2;

        for (int k = i; k < i1-2; k++) {
          for (int l = j; l < j1-2; l++) {
            if (a[k][l] == '1') {
              add(k,l, k+1,l, k,l+1);
            }
          }
        }

        for (int k = i1-2; k < i1; k++) {
          for (int l = j; l < j1-2; l++) {
            if (a[k][l] == '1') {
              add(k,l, k,l+1, (k==i1-1 ? k-1 : k+1),l+1);
            }
          }
        }

        for (int k = i; k < i1-2; k++) {
          for (int l = j1-2; l < j1; l++) {
            if (a[k][l] == '1') {
              add(k,l, k+1,l, k+1,(l==j1-1 ? l-1 : l+1));
            }
          }
        }

        {
          int k = i1-2, l = j1-2;
          int A = a[k][l]-'0';
          int B = a[k][l+1]-'0';
          int C = a[k+1][l]-'0';
          int D = a[k+1][l+1]-'0';
          int sum = A+B+C+D;
          int pick = (sum%2 == 0);
          if (D == pick) add(k,l, k+1,l, k,l+1);
          if (B == pick) add(k,l, k+1,l, k+1,l+1);
          if (C == pick) add(k,l, k+1,l+1, k,l+1);
          if (A == pick) add(k+1,l+1, k+1,l, k,l+1);
        }
      }
    }
    cout << ans.size() << endl;
    for (auto v : ans) {
      for (int x : v) cout << x << ' ';
      cout << endl;
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        assert(a[i][j] == '0');
        //cout << a[i][j] << ' ';
      }
      //cout << endl;
    }
  }
}