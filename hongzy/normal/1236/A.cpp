#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
#define fs first
#define sc second
const int N = 1e5 + 10;
const int mo = 1e9 + 7;

int main() {
	ios :: sync_with_stdio(false);
	int T; cin >> T;
	while(T --) {
		int a, b, c, ans = 0;
		cin >> a >> b >> c;
		for(int i = 0; i <= 100; i ++) {
			for(int j = 0; j <= 100; j ++) {
				if(a - i >= 0 && b - 2 * i - j >= 0 && c - 2 * j >= 0) {
					ans = max(ans, a + b + c - (a - i) - (b - 2 * i - j) - (c - 2 * j));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}