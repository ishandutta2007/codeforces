#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,x,y,f[125][125];

ll fuck(ll t,ll x,ll y){
	memset(f,0,sizeof(f));
	f[0][0]=max(0ll,t-x-y+1);
	for(i=0;i<=120;i++){
		for(j=0;j<=120;j++){
			f[i][j+1]+=(f[i][j]+1)/2;
			f[i+1][j]+=(f[i][j])/2;
		}
	}
	return f[x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>x>>y;
		if(fuck(n,x,y)!=fuck(n-1,x,y))cout<<"YES\n";
		else cout<<"NO\n";
	}
}