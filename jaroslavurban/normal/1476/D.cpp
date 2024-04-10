#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;

const int N=300100;
int n,par[N],siz[N];
int vis[N][2];
string s;

int dfs(int u,int m,int p){
	if(vis[u][m])return 0;
	vis[u][m]=true;
	if(m==0)par[u]=p;
	return 1+(u&&((s[u-1]=='L'&&m==0)||(s[u-1]=='R'&&m==1))?dfs(u-1,!m,p):0)
					+(u!=n&&((s[u]=='R'&&m==0)||(s[u]=='L'&&m==1))?dfs(u+1,!m,p):0);
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>s;
		for(int i=0;i<=n;++i)par[i]=-1;
		for(int i=0;i<=n;++i)vis[i][0]=vis[i][1]=0;
		for(int i=0;i<=n;++i){
			if(par[i]!=-1)cout<<siz[par[i]]<<" ";
			else cout<<(siz[i]=dfs(i,0,i))<<" ";
		}
		cout<<endl;
	}
}