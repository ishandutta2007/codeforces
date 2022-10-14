#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n, p, k;
		cin >> n >> p >> k;p--;
		vector<int> a;
		char c;
		for(int i = 0; i < n; i++) {
			cin >> c;
			a.push_back(c-'0');
		}
		int x, y;
		for(int i = n; i--;) {
			a[i] ^= 1;
			if(i+k < n) a[i] += a[i+k];
		}
		cin >> x >> y;
		int ans = 1<<30;
		for(int i = p; i < n; i++) {
			ans = min(ans, (i-p)*y + a[i]*x);
		}
		cout << ans << '\n';
	}
}