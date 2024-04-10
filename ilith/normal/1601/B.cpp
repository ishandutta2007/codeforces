#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
#define ROF(i,a,b) for(rgi i=a;i>=b;--i)
#define log(a) cerr<<#a<<'='<<(a)<<" @ line "<<__LINE__<<endl
typedef long long ll;
using namespace std;
const int N=400010;
int n,a[N],b[N],p[N],nw,t=1,nxt[N];
vector<int>pre[N],ans;
signed main(){
	scanf("%d",&n);
	FOR(i,1,n)scanf("%d",a+i),p[i]=i,nxt[i]=-1;
	FOR(i,1,n)scanf("%d",b+i),pre[i+b[i]].pbk(i);
	sort(p+1,p+n+1,[&](int x,int y){return x-a[x]<y-a[y];});
	while(1){
		int r=0,f=0;
		while(t<=n&&p[t]-a[p[t]]<=nw){
			rgi g=p[t];
			nxt[g]=nw,f=1;
			for(rgi x:pre[g])r=max(r,x);
			++t;
		}
		nw=r;
		if(!f)break;
	}
	if(!~nxt[n])puts("-1"),exit(0);
	for(rgi i=nxt[n];i;i=nxt[i])ans.pbk(i),i+=b[i];
	ans.pbk(0),printf("%d\n",ans.size());
	for(rgi x:ans)printf("%d ",x);
	return 0;
}