#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
const LL P=998244353;
LL gcd(LL a,LL b) {
    return b?gcd(b,a%b):a;
}
LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
int n;
struct node{
	LL w,du;
}a[N];
bool cmp(node x,node y){
	return x.w>y.w;
}
int main(){
	int T,u,v;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) {
			scanf("%lld",&a[i].w);
			a[i].du=-1;
		}
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			++a[u].du;
			++a[v].du;
		}
		sort(a+1,a+1+n,cmp);
		LL ans=0;
		for(int i=1;i<=n;++i) ans+=a[i].w;
		printf("%lld",ans);
		int j=1;
		for(int i=2;i<n;++i){
			while(a[j].du<=0&&j<=n) ++j;
			--a[j].du;
			ans+=a[j].w;
			printf(" %lld",ans);
		}
		puts("");
	}
	return 0;
}