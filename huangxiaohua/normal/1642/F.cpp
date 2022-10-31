#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t,it,mp[1005000];
int num[1005000];
struct SB{
	int f[6],w;
	bool operator<(const SB x)const{return w<x.w;}
}s[100500];
map<int,int> mp2;
vector<int> v[1005000];
bitset<100005> sb[5005],vis;
int res=2000000005;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)cin>>s[i].f[j];
		cin>>s[i].w;
	}
	for(i=1;i<=2000;i++)sb[i].set();
	sort(s+1,s+n+1);
	it=0;
	for(i=1;i<=m;i++)for(j=1;j<=n;j++)if(!mp2[s[j].f[i]])mp2[s[j].f[i]]=++it;
	for(i=1;i<=m;i++)for(j=1;j<=n;j++)s[j].f[i]=mp2[s[j].f[i]];
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)num[s[i].f[j]]++;
	it=0;
	for(i=1;i<=500000;i++)if(num[i]>=500)mp[i]=++it;
	vis.set();
	int t1;
	for(i=n;i>=1;i--){
		for(j=1;j<=m;j++){
			t1=s[i].f[j];
			if(mp[t1])vis&=sb[mp[t1]];
			else for(auto k:v[t1])vis[k]=0;
		}
		k=vis._Find_next(i);
		if(k<=n)res=min(res,s[i].w+s[k].w);
		vis.set();
		for(j=1;j<=m;j++){
			t1=s[i].f[j];
			if(mp[t1])sb[mp[t1]][i]=0;
			else v[t1].push_back(i);
		}
	}
	if(res==2000000005)cout<<-1;
	else cout<<res;
}