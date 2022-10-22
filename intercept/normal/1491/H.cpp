#include<bits/stdc++.h>
#define ll long long
#define be(x) (x-1)/B
#define lc(x) be(x)*B+1
#define rc(x) be(x)*B+B
using namespace std;
const int M=2e5+9;
const int B=319;
int n,q,f[M],cnt[B];
ll a[M],tag[B];
int A(int x){
	return x==1?0:max(1ll,a[x]+tag[be(x)]);
}
void change(int x,int v){
	cnt[x]+=v;
	if(cnt[x]>B)return;
	for(int i=x*B+1;i<=x*B+B;++i)
		f[i]=A(i)<=x*B?i:f[A(i)];
}
int lca(int x,int y){
	while(f[x]!=f[y]){if(A(f[x])<A(f[y]))swap(x,y);x=A(f[x]);}
	while(x!=y){if(x<y)swap(x,y);x=A(x);}
	return x;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i+=B)change(i/B,0);
	for(int i=1,o,l,r,x;i<=q;++i){
		scanf("%d",&o);
		if(o==1){
			scanf("%d%d%d",&l,&r,&x);
			for(int i=lc(l);i<     l;++i)a[i]+=x;
			for(int i=r+1  ;i<=rc(r);++i)a[i]+=x;
			for(int i=be(l);i<=be(r);++i){
				tag[i]-=x;change(i,i!=be(l)&&i!=be(r));
			}
		}
		else {
			scanf("%d%d",&l,&r);
			printf("%d\n",lca(l,r));
		}
	}
	return 0;
}