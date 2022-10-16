#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define N 1000004
#define ll long long
#define mid (l+r>>1)
#define ls k<<1
#define rs k<<1|1
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define IOS ios::sync_with_stdio(0);

int T,n,k,b[N],fl,i,j,sz[N];
vector<int>son[N];
inline bool cmp(int x,int y){
	return sz[x]<sz[y];
}
void dfs1(int now){
	sz[now]=1;
	for(int i=0;i<son[now].size();++i){
		dfs1(son[now][i]);
		sz[now]+=sz[son[now][i]];
	}
	sort(son[now].begin(),son[now].end(),cmp);
}
void dfs2(int now){
	if(now)cout<<now<<" ";
	for(int i=0;i<son[now].size();++i){
		dfs2(son[now][i]);
	}
}
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n;k=0;
		for(i=0;i<=n;++i)son[i].clear();
		for(i=1;i<=n;++i)cin>>b[i];fl=0;
		for(i=1;i<=n;++i)if(b[i]>i)++k;
		for(i=1;i<=n;++i)if(b[i]==n+1)fl=1,son[0].push_back(i);
		for(i=1;i<=n;++i)if(b[i]==0)fl=2,son[0].push_back(i);
		for(i=1;i<=n;++i){
			if(b[i]<=n&&b[i])son[b[i]].push_back(i);
		}
		cout<<k<<"\n";
		dfs1(0);
		dfs2(0);cout<<'\n';
	}
}