#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define IOS ios::sync_with_stdio(0)
#define ls k<<1
#define rs k<<1|1
int n,m,T,i,x,y,v,k,z,j,c[505][505],to[505][505];
char ch;
string s;
ll l,r;
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;c[i][i]=0,++i)for(j=1;j<=n;++j)c[i][j]=1e9,to[i][j]=0;
		for(i=1;i<=m;++i)cin>>x>>y>>v,c[x][y]=c[y][x]=1,to[x][y]=to[y][x]=(to[x][y]==0)?v:min(to[x][y],v);
		for(i=1;i<=n;++i){
			for(j=1;j<=n;++j){
				for(k=1;k<=n;++k){
					c[j][k]=min(c[j][i]+c[i][k],c[j][k]);
				}
			}
		}
		ll ans=1e18;
		for(i=1;i<=n;++i){
			for(j=1;j<=n;++j){
				if(to[i][j]){
					int hh=c[1][i]+c[j][n]; 
					for(z=1;z<=n;++z){
						hh=min(hh,min(c[i][z],c[j][z])+c[1][z]+c[n][z]+1);
					}
					ans=min(ans,1ll*to[i][j]*(hh+1));
					
				}
			}
		}
		cout<<ans<<"\n";
	}
}