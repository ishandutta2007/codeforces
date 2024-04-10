#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=209;
int n,m;
int ma[M][M],mi[M][M],vis[M][M],a[M],in[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)vis[i][i]=1;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		if(vis[u][v]){
			if(w){
				ma[u][v]=min(ma[u][v],1);
				mi[u][v]=max(mi[u][v],1);
				ma[v][u]=min(ma[v][u],-1);
				mi[v][u]=max(mi[v][u],-1);
			}
			else{
				ma[u][v]=min(ma[u][v],1);
				mi[u][v]=max(mi[u][v],-1);
				ma[v][u]=min(ma[v][u],1);
				mi[v][u]=max(mi[v][u],-1);
			}
		}
		else{
			if(w){
				ma[u][v]=1;
				mi[u][v]=1;
				ma[v][u]=-1;
				mi[v][u]=-1;
			}
			else{
				ma[u][v]=1;
				mi[u][v]=-1;
				ma[v][u]=1;
				mi[v][u]=-1;
			}
		}
		vis[u][v]=vis[v][u]=1;
		
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(vis[i][k]&&vis[k][j]){
					if(vis[i][j]){
						if((ma[i][j]&1)!=((ma[i][k]+ma[k][j])&1)){
							cout<<"NO\n";
							return 0;
						}
						mi[i][j]=max(mi[i][j],mi[i][k]+mi[k][j]);
						ma[i][j]=min(ma[i][j],ma[i][k]+ma[k][j]);
					}
					else {
						mi[i][j]=mi[i][k]+mi[k][j];
						ma[i][j]=ma[i][k]+ma[k][j];
					}
					vis[i][j]=1;
				}
			}
		}
	}
	int x=1,y=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(ma[i][j]<mi[i][j]){
				cout<<"NO\n";
				return 0;
			}
			if(ma[x][y]<ma[i][j])x=i,y=j;
		}
	}
	a[x]=0;
	a[y]=ma[x][y];
	in[x]=in[y]=1;
	cout<<"YES\n"<<ma[x][y]<<"\n";
	for(int i=1;i<=n;++i){
		for(int j=0;j<n;++j){
			bool bol=0;
			for(int k=1;k<=n;++k){
				if(in[k]){
					if((ma[k][i]&1)!=((j-a[k])&1)||ma[k][i]<j-a[k]||mi[k][i]>j-a[k])bol=1;
				}
			}
			if(!bol){
				a[i]=j;
				break;
			}
		}
		cout<<a[i]<<" \n"[i==n];
	}
	return 0;
}
/*
3 10
1 4 2
1
1 4



1000000000
0010000000
0010000000
0000001000
0001000000
0100000000
0000010000
0000000010
*/