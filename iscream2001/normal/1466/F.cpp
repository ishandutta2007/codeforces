#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+10;
const LL P=1e9+7;
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
int n,m,k;
int fa[N];
int tp;
int st[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=m;++i) fa[i]=i;
	tp=0;
	int x,y;
	for(int i=1;i<=n;++i){
		scanf("%d",&k);
		if(k==1){
			scanf("%d",&x);y=0;
		}
		else{
			scanf("%d%d",&x,&y);
		}
		x=find(x);
		y=find(y);
		//cout<<x<<" "<<y<<endl;
		if(x==y) continue;
		st[++tp]=i;fa[x]=y;
	}
	LL res=1;
	for(int i=1;i<=tp;++i) res=(res+res)%P;
	printf("%lld %d\n",res,tp);
	for(int i=1;i<=tp;++i) printf("%d ",st[i]);puts("");
	return 0;
}