#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 5050, mod =998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int ans = 0, cnt = 0, lc = 0, lds = 0, lst = 1<<30;
		for(auto &i : a) {cin >> i;
			if(i < lst) lds++;
			//cout << i << " " << lds << endl;
			if(lds > cnt) {
				lds = 1;
				int cur = &i-&a[0];
				cnt = cur-lc;
				lc = cur;
				ans++;
			}
			lst = i;
		}
		cout << ans-1 << '\n';
	}
	return 0;
}