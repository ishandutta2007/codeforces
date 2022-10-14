#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 3302, mod = 1e9 + 7;
int n, a[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		int p = 0, ans = 1<<30;
		for(int i = 1; i <= n; i++) {
			p += a[i];
			int c = i!=n, s = 0;
			for(int j = i+1; j <= n; j++) {
				s += a[j];
				if(s == p) s = 0, c+=j!=n;
			}
			if(s == 0) ans = min(ans, n-1-c);
		}
		if(ans == 1<<30) ans = -1;
		cout << ans << '\n';
	}
}