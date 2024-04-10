#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[44][200500],g[44][200500],x,y,res=1e9;
map<int,map<int,int> > mp;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>t;
	for(i=1;i<=t;i++){
		cin>>j>>k;
		mp[j][k]=1;
	}
	f[0][1]=1;
	g[0][1]=1;
	for(t=0;t<=40;t++){
		if(f[t][n]==m||g[t][m]==n){
			cout<<t;return 0;
		}
		for(i=1;i<=n;i++){
			if(!f[t][i])continue;
			x=i;
			y=f[t][i];
			k=x+y+mp[x].count(y);
			f[t+1][x]=min(m,max(f[t+1][x],k));
			g[t+1][y]=min(n,max(g[t+1][y],k));
		}
		for(i=1;i<=m;i++){
			if(!g[t][i])continue;
			x=g[t][i];
			y=i;
			k=x+y+mp[x].count(y);
			f[t+1][x]=min(m,max(f[t+1][x],k));
			g[t+1][y]=min(n,max(g[t+1][y],k));
		}
	}
	if(f[41][n]){
		k=0;
		j=f[41][n];
		while(1){
			if(j==m){
				res=min(res,k+41);
				break;
			}
			j=min(m,n+j+mp[n][j]);
			k++;
		}
	}
	if(g[41][m]){
		k=0;
		j=g[41][m];
		while(1){
			if(j==n){
				res=min(res,k+41);
				break;
			}
			j=min(n,m+j+mp[j][m]);
			k++;
		}
	}
	cout<<res;
}