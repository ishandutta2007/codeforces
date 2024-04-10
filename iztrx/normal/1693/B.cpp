#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int T,n,ans,i,x,l[N],r[N];
vector<int>son[N];
int dfs(int now){
	long long ad=0;
	for(int T,i=0;i<son[now].size();++i){
		T=son[now][i];ad+=dfs(T); 
	}
	ad=min(ad,1ll*r[now]);
	if(ad<l[now])ad=r[now],++ans;
	return ad;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(i=1;i<=n;++i)son[i].clear();
		for(i=2;i<=n;++i)cin>>x,son[x].push_back(i);
		for(i=1;i<=n;++i)cin>>l[i]>>r[i];
		dfs(1);cout<<ans<<"\n";
	}
}