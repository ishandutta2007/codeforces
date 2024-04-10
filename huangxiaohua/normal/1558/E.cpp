#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,vis[2050];
ll a[2050],b[2050],l,r,md,res,num,lst,cur;
vector<int> v[2050];

bool dfs(int x,int fa){
	if(!vis[x])vis[x]=1;
	if(vis[x]!=2)cur+=b[x];
	for(auto i:v[x]){
		if(i==fa)continue;
		if(vis[x]==2&&vis[i]==2)continue;
		if(cur<=a[i])continue;
		if(vis[i]||dfs(i,x)){
			num+=(vis[x]!=2);
			vis[x]=2;
			return 1;
		}
	}
	if(vis[x]!=2)cur-=b[x];
	if(vis[x]==1)vis[x]=0;
	return 0;
}

bool chk2(ll x){
	num=1;cur=x;
	vis[1]=2;
	while(num!=n){
		for(int i=1;i<=n;i++){
			if(vis[i]!=2)continue;
			if(dfs(i,0))goto aaa;
		}
		return 0;
		aaa:;
	}
	return 1;
}

int main() {
	cin>>t;
	while(t--){
		cin>>n>>m;
		v[1].clear();
		for(i=2;i<=n;i++)v[i].clear(),cin>>a[i];
		for(i=2;i<=n;i++)cin>>b[i];
		for(i=1;i<=m;i++){
			cin>>j>>k;
			v[j].push_back(k);
			v[k].push_back(j);
		}
		l=0;r=2e9;res=2e9;
		while(l<=r){
			md=(l+r)/2;
			if(chk2(md))res=min(res,md),r=md-1;
			else l=md+1;
			memset(vis,0,sizeof(vis));
		}
		cout<<res<<'\n';
	}
}