#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.length();
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			if(s[i-1]=='['||s[i-1]==']')arr[i] = 1;
			if(i>1)arr[i]+=arr[i-2];
		}
		int q;
		cin >> q;
		while(q--){
			int l,r;
			cin >> l >> r;
			int v = arr[r]-arr[l-1];
			int v2 = arr[r-1];
			if(l>1)v2-=arr[l-2];
			cout << abs(v-v2) << "\n";
		}
	}
	return 0;
}