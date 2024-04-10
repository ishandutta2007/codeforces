#include<bits/stdc++.h>
using namespace std;
int len,t,n,i,j,m,a[50][50],x,y,s,u,ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;++i)for(j=1;j<=m;++j)cin>>a[i][j];
		len=n+m;ans=0;
		for(i=2;i<(len+3)/2;++i){
			x=i;y=len+2-i;u=s=0;
			for(j=max(1,x-m);j<=min(n,x-1);++j)++s,u+=a[j][x-j];
			for(j=max(1,y-m);j<=min(n,y-1);++j)++s,u+=a[j][y-j];
			ans+=min(u,s-u);
		}cout<<ans<<"\n";
	}
}