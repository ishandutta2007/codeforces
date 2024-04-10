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

int p[6] = {4, 5, 6, 3, 2, 1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   string s; cin >> s; int n = s.size() - 1;
   int r = s[n] - 'a';
   r = p[r];

   ll x = 0;
   rep(i, n) {
      x = x * 10 + (s[i] - '0');
   }

   ll sol = (ll) ((ll) (x - 1) / 4) * 16;

   x = x % 2;
   if(x == 0) sol += 7;

   sol += r;

   cout << sol;
}