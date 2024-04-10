#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
int n,m,q,num;
map<pii,int>mp;
int ans=1e9;
void dfs(int x,int y,int z){
	if(x==n&&y==m){
		ans=min(ans,z);
		return;
	}
	int t=x+y;
	if(mp[make_pair(x,y)]){
		t++;
		if(y!=m)dfs(x,min(m,t),z+1);
		if(n!=x)dfs(min(n,t),y,z+1);
		return;
	}
	if(x<y){
		if((t>=m&&y!=m)||x==n)dfs(x,min(t,m),z+1);
		else dfs(min(n,t),y,z+1);
	}
	else{
		if((t>=n&&x!=n)||y==m)dfs(min(n,t),y,z+1);
		else dfs(x,min(t,m),z+1);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		mp[make_pair(x,y)]=i;
	}
	if(mp[make_pair(1,1)]){
		dfs(1,min(3,m),1);
		dfs(min(3,n),1,1);
	}
	else dfs(1,2,1),dfs(2,1,1);
	printf("%d\n",ans);
	return 0;
}