#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 602, mod = 1e9 + 7;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int x;
		cin >> x;
		int ans = 1ll<<30;
		for(int msk = 0; msk < 1<<9; msk++) {
			ll s = 0;
			string a;
			for(int i = 0; i < 9; i++) if((msk>>i)&1) {
				s += i+1;
				a += char('1'+i);
			}
			if(s == x) ans = min(ans, stoi(a));
		}
		if(ans == 1<<30) ans = -1;
		cout << ans << '\n';
	}
}