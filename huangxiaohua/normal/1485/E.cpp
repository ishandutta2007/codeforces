#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,dep[200500]={-1},a[200500],sb,it,mn[200500],mx[200500],fa[200500];
vector<int> v[200500],q[200500];
ll dp[200500],mn2[200500],mx2[200500],res;

void dfs(int x,int fa,int d){
	dep[x]=d;sb=max(d,sb);
	q[d].push_back(x);
	for(auto i:v[x]){
		dfs(i,x,d+1);
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);sb=res=0;
		for(i=1;i<=n;i++){
			dp[i]=0;
			mn[i]=1145141919;
			mx[i]=mx2[i]=mn2[i]=-1145141919;
			v[i].clear();
			q[i].clear();
		}
		for(i=2;i<=n;i++){
			scanf("%d",&k);
			fa[i]=k;
			v[k].push_back(i);
		}
		for(i=2;i<=n;i++){
			scanf("%d",&a[i]);
		}
		dfs(1,0,1);
		for(i=1;i<=sb;i++){
			for(auto j:q[i]){
				dp[j]=dp[fa[j]]+max(a[fa[j]]-mn[i-1],mx[i-1]-a[fa[j]]);
				dp[j]=max(dp[j],max(mn2[i-1]+a[fa[j]],mx2[i-1]-a[fa[j]]));
				mn[i]=min(mn[i],a[j]);
				mx[i]=max(mx[i],a[j]);
				mn2[i]=max(dp[j]-a[j],mn2[i]);
				mx2[i]=max(dp[j]+a[j],mx2[i]);
			}
		}
		for(auto j:q[sb]){
			res=max(res,dp[j]+max(a[j]-mn[sb],mx[sb]-a[j]));
		}
		printf("%lld\n",res);
	}
}