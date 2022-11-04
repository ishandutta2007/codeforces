#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
bool vis[N];
int rook[N][2];
int yx[N],xx[N];
vector<int>fuckme;

int dfs(int u,int p){
	fuckme.push_back(u);
	if(vis[u])return 0;
	vis[u]=true;
	if(rook[u][0]==rook[u][1])return 0;
	int want1=rook[u][0];
	int want2=rook[u][1];
	if(yx[want1]==-1)return 1;
	if(xx[want2]==-1)return 1;
	if(yx[want1]!=p){
		int res=dfs(yx[want1],u);
		if(!res)return 2;
		return res+1;
	}
	if(xx[want2]!=p){
		int res=dfs(xx[want2],u);
		if(!res)return 2;
		return res+1;
	}
	return 2;
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,m;cin>>n>>m;
		for(int i=0;i<m;++i)cin>>rook[i][0]>>rook[i][1];
		for(int i=0;i<m;++i){--rook[i][0];--rook[i][1];}
		for(int i=0;i<=n;++i)yx[i]=xx[i]=-1;
		for(int i=0;i<=n;++i)vis[i]=0;
		for(int i=0;i<m;++i)xx[rook[i][0]]=yx[rook[i][1]]=i;
		int res=0;
		for(int i=0;i<m;++i){
			res+=dfs(i,i);
			for(auto u:fuckme)xx[rook[u][0]]=yx[rook[u][1]]=-1;
			fuckme.clear();
		}
		cout<<res<<endl;
	}
}