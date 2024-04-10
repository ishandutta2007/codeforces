#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int mod = 1e9 + 7;
int add(int x, int y) {
	x += y;
	if(x >= mod) return x - mod;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if(x < 0) return x + mod;
	return x;
}
int mul(int x, int y) {
	return (ll) x * y % mod;
}

const int MAXN = 1e5 + 5;

char c[5][5];

void check() {
   bool ok = false;
   rep(i, 4) rep(j, 4) {
      bool can1 = true;
      rep(k, 3) {
         if(k + j >= 4 || c[i][j + k] != 'x') can1 = false;
      }
      bool can2 = true;
      rep(k, 3) {
         if(k + i >= 4 || c[i + k][j] != 'x') can2 = false;
      }
      bool can3 = true;
      rep(k, 3) {
         if(k + j >= 4 || k + i >= 4 || c[i + k][j + k] != 'x') can3 = false;
      }
      bool can4 = true;
      rep(k, 3) {
         if(k + j >= 4 || i - k < 0 || c[i - k][j + k] != 'x') can4 = false;
      }
      ok |= can1;
      ok |= can2;
      ok |= can3;
      ok |= can4;
   }
   if(ok) {
      cout << "YES";
      exit(0);
   }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   rep(i, 4) rep(j, 4) cin >> c[i][j];
   rep(i, 4) rep(j, 4) {
      if(c[i][j] != '.') continue;
      char bilo = 'x';
      swap(bilo, c[i][j]);
      check();
      swap(bilo, c[i][j]);
   }
   cout << "NO";
}