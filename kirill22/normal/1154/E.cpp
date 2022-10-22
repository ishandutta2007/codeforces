#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n,k,kol = 1;
	cin >> n >> k;
	set<pair<int,int>> a,st;
	vector<int> b(n),ans(n,-2);
	for(int i=0;i<n;i++){
		cin >> b[i];
		a.insert({- b[i],i});
		st.insert({i,b[i]});
	}
	while(! a.empty()){
		kol = (kol + 1)%2;
		int x = a.begin() -> second, tmp1 = k;
		a.erase({- b[x],x});
		auto y = st.find({x,b[x]});
		ans[x] = kol;
		while(tmp1--){
			auto tmp3 = next(y);
			if(tmp3 == st.end()){ break;}
			a.erase({- (tmp3 -> second),tmp3 -> first});
			ans[tmp3 -> first] = kol;
			st.erase(tmp3);
		}
		tmp1 = k;
		while(tmp1--){
			if(y == st.begin()){ break;}
			auto tmp3 = prev(y);
			a.erase({- (tmp3 -> second),tmp3 -> first});
			ans[tmp3 -> first] = kol;
			st.erase(tmp3);
		}
		st.erase(y);
	}
	for(int i=0;i<n;i++){
		cout << ans[i] + 1;
	}
	return 0;
}