#include<cstdio>
#include<vector>
using namespace std;
int T,n,x,d,mx,xx,dd;
vector<int> q,vec[1100],que[1100];
void Query(vector<int> &vec){
	putchar('?'); printf(" %d",(int)vec.size());
	for (int v:vec) printf(" %d",v);
	putchar('\n'); fflush(stdout);
}
void dfs(int u,int d,int fa){
	que[d].emplace_back(u); mx=max(mx,d);
	for (int v:vec[u]){
		if (v==fa) continue;
		dfs(v,d+1,u);
	}
}
bool check(int mid){
	Query(que[mid]); scanf("%d%d",&xx,&dd);
	return dd==d;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n); mx=0; int u,v;
		for (int i=1;i<=n;i++) vec[i].clear();
		for (int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		for (int i=0;i<n;i++) que[i].clear();
		q.clear();
		for (int i=1;i<=n;i++) q.emplace_back(i);
		Query(q); scanf("%d%d",&x,&d);
		dfs(x,0,0); q.clear();
		int l=(d-1)/2+1,r=min(mx,d),mid,ans;
		while (l<=r){
			mid=(l+r)>>1;
			if (check(mid)){
				ans=xx;
				l=mid+1;
			} else r=mid-1;
		}
		for (int i=0;i<n;i++) que[i].clear();
		dfs(ans,0,0);
		Query(que[d]); scanf("%d%d",&x,&d);
		printf("! %d %d\n",ans,x); fflush(stdout);
		scanf("%*s");
	}
	return 0;
}