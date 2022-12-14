#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q; cin >> n >> q;
	string s; cin >> s;
	vector<int> pa(n + 1), pb(n + 1), pc(n + 1), pd(n + 1), pe(n + 1), pf(n + 1);
	int now = 0;
	for(int i = 0; i < n; ++i){
		pa[i + 1] = pa[i];
		if(now == s[i] - 'a') ++pa[i + 1];
		now = (now + 1) % 3;
	}
	now = 1;
	for(int i = 0; i < n; ++i){
		pb[i + 1] = pb[i];
		if(now == s[i] - 'a') ++pb[i + 1];
		now = (now + 1) % 3;
	}
	now = 2;
	for(int i = 0; i < n; ++i){
		pc[i + 1] = pc[i];
		if(now == s[i] - 'a') ++pc[i + 1];
		now = (now + 1) % 3;
	}
	now = 0;
	for(int i = 0; i < n; ++i){
		pd[i + 1] = pd[i];
		if(now == s[i] - 'a') ++pd[i + 1];
		now = (now + 2) % 3;
	}
	now = 1;
	for(int i = 0; i < n; ++i){
		pe[i + 1] = pe[i];
		if(now == s[i] - 'a') ++pe[i + 1];
		now = (now + 2) % 3;
	}
	now = 2;
	for(int i = 0; i < n; ++i){
		pf[i + 1] = pf[i];
		if(now == s[i] - 'a') ++pf[i + 1];
		now = (now + 2) % 3;
	}
	while(q--){
		int l, r; cin >> l >> r;
		cout << r - l + 1 - max({pa[r] - pa[l - 1], pb[r] - pb[l - 1], pc[r] - pc[l - 1], pd[r] - pd[l - 1], pe[r] - pe[l - 1], pf[r] - pf[l - 1]}) << '\n';
	}
	return 0;
}