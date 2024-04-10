#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		string s;
		cin >> s;
		s = " " + s;
		vector<int>psa(n*m+1);
		for(int i = 1; i<=n*m; i++){
			if(s[i]=='1'){
				psa[i]++;
			}
			psa[i]+=psa[i-1];
		}
		vector<int>val(n*m+1);
		for(int i = 1; i<=m; i++){
			val[i] = (psa[i]>0);
		}
		for(int i = m+1; i<=n*m; i++){
			if(psa[i]-psa[i-m]>0){
				val[i] = 1;
			}
		}
		vector<int>ans(n*m+5);
		for(int i = 1; i<=n*m; i++){
			ans[i] = val[i];
		}
		for(int i = m+1; i<=n*m; i++){
			ans[i]+=ans[i-m];
		}
		vector<int>tim(m+5,n*m+1);
		for(int i = 1; i<=n*m; i++){
			if(s[i]=='1'){
				int v = i%m;
				if(v==0)v = m;
				tim[v] = min(tim[v],i);
			}
		}
		vector<int>ans2(n*m+5);
		for(int i = 1; i<=m; i++){
			ans2[tim[i]]++;
		}
		for(int i = 1; i<=n*m; i++){
			ans2[i]+=ans2[i-1];
		}
		for(int i = 1; i<=n*m; i++){
			cout << ans[i]+ans2[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}