#include<stdio.h>
#include<map>
using namespace std;
const int maxn=200005;
int n,q;
long long ans;
int a[maxn],cnt[maxn];
map<int,int>g[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),ans+=a[i];
	scanf("%d",&q);
	while(q--){
		int s,t,u;
		scanf("%d%d%d",&s,&t,&u);
		if(g[s].find(t)!=g[s].end()){
			int v=g[s][t];
			cnt[v]--;
			if(cnt[v]<a[v])
				ans++;
			g[s].erase(t);
		}
		if(u){
			if(cnt[u]<a[u])
				ans--;
			cnt[u]++;
			g[s][t]=u;
		}
		printf("%lld\n",ans);
	}
	return 0;
}