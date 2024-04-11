#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;

int norm(int x, int d){
	if(d == 1) return 0;
	x %= (2 * d - 2);
	if(x >= d) return 2 * d - 2 - x;
	return x;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		vector<lint> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		auto ok = [&](lint x){
			vector<lint> stk(n);
			for(int i = n - 1; i >= 0; i--){
				if(a[i] + stk[i] < x) return false;
				if(i >= 2){
					lint d = (a[i] + stk[i] - x) / 3;
					d = min(d, a[i] / 3);
					stk[i - 1] += d;
					stk[i - 2] += 2 * d;
				}
			}
			return true;
		};
		lint s = 0, e = 1e9;
		while(s != e){
			lint m = (s + e) / 2;
			if(!ok(m)) e = m;
			else s = m + 1;
		}
		cout << s - 1 << "\n";
	}
}