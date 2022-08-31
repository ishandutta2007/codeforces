#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int t,n,m,k,f[N];
struct edg{
	int a,b,c;
}e[N];
inline bool cmp(edg a,edg b){
	return a.c<b.c;
}
inline int find(int u){
	if(f[u]==u) return u; return f[u]=find(f[u]);
}
int main(){
	cin>>t;
	while(t--){
		scanf("%d%d%d",&n,&m,&k); long long ans=1e18,sum=0;
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
		sort(e+1,e+m+1,cmp); int TAG=1;
		for(int i=1;i<=m;i++){
			if(find(e[i].a)!=find(e[i].b)){
				f[find(e[i].a)]=find(e[i].b),TAG++;
				if(e[i].c>k) sum+=e[i].c-k;
			}
			if(TAG==n) ans=min(ans,1ll*abs(k-e[i].c));
		}
		if(sum>0) printf("%lld\n",sum);
		else printf("%lld\n",ans);
	}
	return 0;
}
//1
//3 2 10
//1 2 8
//1 3 10