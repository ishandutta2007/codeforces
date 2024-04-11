#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<lint, lint>;
const int MAXN = 2005;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		int si = 2e9, ei = 0;
		map<pi, lint> mp;
		lint minWithSi = 1e18;
		lint minWithEi = 1e18;
		for(int i = 0; i < n; i++){
			lint s, e, x; cin >> s >> e >> x;
			if(mp.count(pi(s, e))) mp[pi(s, e)] = min(mp[pi(s, e)], x);
			else mp[pi(s, e)] = x;
			if(si > s){
				si = s;
				minWithSi = 1e18;
			}
			if(si == s) minWithSi = min(minWithSi, x);
			if(ei < e){
				ei = e;
				minWithEi = 1e18;
			}
			if(ei == e) minWithEi = min(minWithEi, x);
			lint ret = 1e18;
			if(mp.count(pi(si, ei))) ret = min(ret, mp[pi(si, ei)]);
			ret = min(ret, minWithSi + minWithEi);
			cout << ret << "\n";
		}
	}
}