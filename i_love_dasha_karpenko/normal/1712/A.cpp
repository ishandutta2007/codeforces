#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

void solve(){
	int n,k;
	cin>>n>>k;
	int res = 0;
	for(int i = 1;i<=n;i+=1){
		int x;
		cin>>x;
		if (i<=k){
			res += x>k;
		}
	}
	cout<<res<<endl;
}
signed main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}