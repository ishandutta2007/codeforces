#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1009],b[1009],d[1009],c[1000009];
vector<int>g[1009];
bool dfs(int u,int k){
	if(u==n+1)return 1;
	if(d[u])return dfs(u+1,k);
	int t=0;
	for(auto v:g[u]){
		if(!d[v])t++;
		d[v]++;
	}
	if(k>=t&&dfs(u+1,k-t))return 1;
	for(auto v:g[u])d[v]--;
	if(t>1){
		d[u]=1;
		if(dfs(u+1,k-1))return 1;
	}
	d[u]=0;
	return 0;
}
bool check(int x){
	for(int i=1;i<=n;++i)d[i]=0,g[i].clear();
	for(int i=1;i<=n;++i){
		for(int j=1;j<i;++j){
			int y=(a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]);
			if(y>=x){
				g[i].emplace_back(j);
				g[j].emplace_back(i);
			}
		}
	}
	return dfs(1,k);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i],&b[i]);
		for(int j=1;j<i;++j){
			c[++m]=(a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]);
		}
	}
	sort(c+1,c+m+1);
	int l=1,r=m,ans;
	while(l<=r){
		int mid=l+r>>1;
		if(check(c[mid]))ans=c[mid],r=mid-1;
		else l=mid+1;
	}
	check(ans);
	for(int i=1;i<=n;++i){
		if(d[i])printf("%d ",i),k--;
	}
	for(int i=1;i<=n;++i){
		if(!d[i]&&k)printf("%d ",i),k--;
	}
	return 0;
}