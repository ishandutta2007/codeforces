#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int M=2e5+109;
int n,p,a[M],f[M][23];
long long ans;
int Min(int l,int r){return a[l]<a[r]?l:r;}
int ask(int l,int r){
	int k=log2(r-l+1);
	return Min(f[l][k],f[r-(1<<k)+1][k]);
}
void solve(int l,int r){
	if(l>=r)return;
	int id=ask(l,r),L=id-1,R=id+1;
	while(L>=l&&__gcd(a[L],a[id])==a[id])ans+=min(a[id],p),L--;
	while(R<=r&&__gcd(a[R],a[id])==a[id])ans+=min(a[id],p),R++;
	if(L+1==id&&L>=l)ans+=p;
	else L++;
	if(R-1==id&&R<=r)ans+=p;
	else R--;
	solve(l,L);
	solve(R,r); 
}
void work(){
	ans=0;
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),f[i][0]=i;
	for(int j=1;j<=19;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			f[i][j]=Min(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	solve(1,n);
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d\n",&T);
	while(T--)work();
	return 0;
}