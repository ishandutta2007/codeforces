#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	array<int, 30> cnt {};
	for(int i = 0; i < n; i++) {
		int l = 0;
		for(int t = a[i]; t;) t/=2, l++;
		cnt[l]++;
	}

	for(int i = 0; i < 30; i++) if(cnt[i] > 2) return cout << "1\n", 0;
	int ans = 1<<30;
	for(int i = 0; i < n; i++) {
		int x = 0, ca = 0;
		for(int j = i; j < n; j++) {
			x ^= a[j];ca++;
			int y = 0, cb = 0;
			for(int k = j+1; k < n; k++) {
				y ^= a[k];cb++;
				//cout << i << " " << j << " " << k << " " << x << " " << y << endl;
				if(x > y) ans = min(ans, ca+cb-2);
			}
		}
	}
	if(ans == 1<<30) ans = -1;
	cout << ans << '\n';
}