//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n';

void solve(){
	int n,m,x,y,d;
	cin>>n>>m>>x>>y>>d;
	if (!((x-d>1 && y+d<m) || (y-d>1 && x+d<n))){
		cout<<"-1\n";
	}
	else{
		cout<<n+m-2<<endl;
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}