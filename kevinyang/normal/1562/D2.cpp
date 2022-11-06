#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,q;
		cin >> n >> q;
		string s;
		cin >> s;
		vector<int>arr(n+1);
		vector<int>psa(n+1);
		map<int,vector<int>>hm;
		for(int i = 1; i<=n; i++){
			if(s[i-1]=='+')arr[i] = 1;
			else arr[i] = -1;
			if(i%2==0)arr[i]*=-1;
			psa[i] = psa[i-1]+arr[i];
			hm[psa[i]+psa[i-1]].push_back(i);
		}
		while(q--){
			int l,r;
			cin >> l >> r;
			if(psa[r]-psa[l-1]==0){
				cout << "0\n";
			}
			else if(l%2==r%2){
				cout << "1\n";
				int v = psa[r]+psa[l-1];
				cout << *lower_bound(hm[v].begin(),hm[v].end(),l) << "\n";
			}
			else{
				cout << "2\n";
				int v = psa[r]+psa[l];
				cout << l << " " << *lower_bound(hm[v].begin(),hm[v].end(),l+1) << "\n";
			}
		}
	}
	return 0;
}