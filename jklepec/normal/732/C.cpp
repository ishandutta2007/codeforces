#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
typedef long long ll;

int x[4][3] = {{0, 0, 0}, {0, 0, 1}, {0, 1, 1}, {1, 1, 1}};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   ll A, B, C; cin >> A >> B >> C;

   ll sol = (ll) (1e18) * 4;

   rep(i, 4) rep(j, 4) {
      ll a = A, b = B, c = C;
      ll tmp = 0;
      a -= x[i][0] + x[j][2];
      b -= x[i][1] + x[j][1];
      c -= x[i][2] + x[j][0];
      tmp += max(max(a, b), c) * 3 - a - b - c;
      sol = min(sol, tmp);
   }

   cout << sol;

}