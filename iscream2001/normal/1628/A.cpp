#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;x%=P;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=3e5+10;
const LL INF=1e18;
void init(){
}
int n;
int a[N],b[N];
int tp;
int q[N];
int vis[N];
void MAIN(){
	scanf("%d",&n);
	for(int i=0;i<=n;++i) vis[i]=0;tp=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=n,m=0;i>=1;--i){
		vis[a[i]]=1;
		while(vis[m]) ++m;
		b[i]=m;
	}
	for(int i=0;i<=n;++i) vis[i]=0;
	for(int i=1,j,m;i<=n;i=j+1){
		q[++tp]=b[i];
		j=i;m=0;
		vis[a[j]]=1;
		while(m!=b[i]){
			if(vis[m]){
				++m;
				continue;
			}
			++j;
			vis[a[j]]=1;
		}
		for(int k=i;k<=j;++k){
			vis[a[k]]=0;
		}
	}
	printf("%d\n",tp);
	for(int i=1;i<=tp;++i) printf("%d ",q[i]);
	puts("");
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}