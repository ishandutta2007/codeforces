#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) for(int i = 0; i < n; ++i)
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

int B, u, l, b, a, s, r;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string str; cin >> str;
	REP(i, str.size()) {
      if(str[i] == 'B') B ++;
      if(str[i] == 'u') u ++;
      if(str[i] == 'l') l ++;
      if(str[i] == 'b') b ++;
      if(str[i] == 'a') a ++;
      if(str[i] == 's') s ++;
      if(str[i] == 'r') r ++;
	}

	cout << min(B, min(u / 2, min(l, min(b, min(a / 2, min(s, r))))));
}