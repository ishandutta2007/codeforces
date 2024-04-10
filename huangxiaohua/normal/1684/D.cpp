#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll f[500500],res,su;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		res=1e18;
		su=0;
		for(i=1;i<=n;i++){
			cin>>f[i];
			su+=f[i];
			f[i]=n-i-f[i];
		}
		sort(f+1,f+n+1);
		res=su;
		for(i=1;i<=m;i++){
		//	printf("NMSL%d %d\n",i,su);
			su+=f[i];
			res=min(res,su-1ll*i*(i-1)/2);
		}
		cout<<res<<'\n';
	}
}