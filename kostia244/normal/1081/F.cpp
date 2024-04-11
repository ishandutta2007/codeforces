#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define int ll
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 998244353;
mt19937 rng(228);
int n, m;
int LOCAL = 0;
vector<int> a;
int ask(int l, int r) {
	cout << "? " << l << " " << r << endl;
	if(LOCAL) {
		if(rng()&1) {
			for(int i = 1; i <= r; i++) a[i] ^= 1;
		} else {
			for(int i = l; i <= n; i++) a[i] ^= 1;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) ans += a[i];
		cout << ans << "::\n";
		return ans;
	}
	int t;
	cin >> t;
	return t;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	if(LOCAL) {
		a = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1};
		n = a.size()-1, m = count(all(a), 1);
	} else {
		cin >> n >> m;
	}
	if(n == 1) {
		cout << "! " << m << endl;
		return 0;
	}
	vector<int> ans;
	if(n&1) {
		int t = 0, lst = m, chn = 1;
		while(t != 3) {
			int cur = ask(2, n);
			if((lst^cur)&1) t ^= chn;
			else t ^= 3^chn;
			lst = cur;
		}
		ans.push_back(lst < m);
		while(t) {
			int cur = ask(2, n);
			if((lst^cur)&1) t ^= chn;
			else t ^= 3^chn;
			lst = cur;
		}
		for(int i = 2; i <= n; i++) {
			int t = 0, lst = m, chn = i%2?1:2;
			while(t != 1) {
				int cur = ask(i-1, i);
				if((lst^cur)&1) t ^= chn;
				else t ^= 3^chn;
				lst = cur;
			}
			ans.push_back((lst-m-i)/(-2));
			while(t) {
				int cur = ask(i-1, i);
				if((lst^cur)&1) t ^= chn;
				else t ^= 3^chn;
				lst = cur;
			}
		}
	} else {
		for(int i = 1; i <= n; i++) {
			int t = 0, lst = m, chn = i%2?1:2;
			while(t != 1) {
				int cur = ask(i, i);
				if((lst^cur)&1) t ^= chn;
				else t ^= 3^chn;
				lst = cur;
			}
			ans.push_back((lst-m-i)/(-2));
			while(t) {
				int cur = ask(i, i);
				if((lst^cur)&1) t ^= chn;
				else t ^= 3^chn;
				lst = cur;
			}
		}
	}
	for(int i = (int)ans.size()-1; i > 0; i--) ans[i] -= ans[i-1];
	cout << "! ";
	for(auto &i : ans) cout << i; cout << endl;
}