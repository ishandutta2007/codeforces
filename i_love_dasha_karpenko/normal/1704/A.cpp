#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';
void solve(){
	int n,m;
	cin>>n>>m;
	string a,b;
	cin>>a>>b;
	if (n<m){
		cout<<"NO\n";
		return;
	}
	char cur = a[0];
	for(int i = 1;i<=n-m;i+=1){
		if (b[0]=='0'){
			cur = min(cur,a[i]);
		}
		else{
			cur = max(cur,a[i]);
		}
	}
	a[n-m] = cur;
	for(int i = 0;i<m;i+=1){
		if (a[i+n-m]!=b[i]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		solve();
	}
}