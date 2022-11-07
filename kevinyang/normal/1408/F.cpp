#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>>ans;
void f(int l, int r){//[l,r)
	if(r<=l+1)return;
	int m = (l+r)/2;
	f(l,m);
	f(m,r);
	for(int i = l; i<m; i++){
		ans.push_back({i,m+i-l});
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	int mx = 1;
	while(mx*2<=n){
		mx*=2;
	}
	f(1,mx+1);
	if(mx==n){
		cout << ans.size() << "\n";
		for(pair<int,int>nxt: ans){
			cout << nxt.first << " " << nxt.second << "\n";
		}
		return 0;
	}
	f(n-mx+1,n+1);
	cout << ans.size() << "\n";
	for(pair<int,int>nxt: ans){
		cout << nxt.first << " " << nxt.second << "\n";
	}
	return 0;
}