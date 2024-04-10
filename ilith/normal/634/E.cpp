#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=800010;
int n,k,c[N],p[N],dp[N],sz[N],su[N],ok[N],l=1,r,u,v,Al;
vector<int>a[N];
int dfs(int x,int f=0){
	rgi g=ok[x];
	sz[x]=1,dp[x]=su[x]=g;
	vector<int>t={0,0};
	int ans=0;
	for(rgi to:a[x])if(to!=f){
		ans=max(ans,dfs(to,x)),sz[x]+=sz[to],ok[x]+=ok[to];
		if(sz[to]==dp[to])dp[x]+=sz[to];
		else t.pbk(dp[to]);
	}
	sort(t.begin(),t.end(),greater<int>());
	dp[x]=g?dp[x]+t[0]:0;
	ans=max(ans,dp[x]+t[1]+(Al-ok[x]==n-sz[x]?n-sz[x]:0));
	t.clear(),t.shrink_to_fit();
	return ans;
}
int chk(int x){
	memset(dp,0,sizeof dp),memset(ok,0,sizeof ok);
	FOR(i,x,n)ok[p[i]]=1;
	return Al=n-x+1,dfs(1);
}
signed main(){
	scanf("%d%d",&n,&k),r=n+1;
	FOR(i,1,n)scanf("%d",c+i),p[i]=i;
	FOR(i,2,n){
		scanf("%d%d",&u,&v);
		a[u].pbk(v),a[v].pbk(u);
	}
	sort(p+1,p+n+1,[](int x,int y){return c[x]<c[y];});
	while(l<r-1){
		int mid=(l+r>>1);
		chk(mid)>=k?l=mid:r=mid;
	}
	printf("%d",c[p[l]]);
	return 0;
}