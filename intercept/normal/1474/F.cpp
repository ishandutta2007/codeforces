#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,a[59];
ll ans,dow,p[59],mi[59],ma[59];
ll l[59][59],r[59][59],c[10009];
struct Matrix{
	ll d[59][59];
	Matrix(){
		for(int i=0;i<=n+1;++i)
		for(int j=0;j<=n+1;++j)
			d[i][j]=0;
	}
	ll *operator [] (const ll&l){
		return d[l];
	}
	Matrix operator * (Matrix&o)const{
		Matrix rex;
		for(int i=0;i<=n+1;++i)
		for(int j=0;j<=n+1;++j)
		for(int k=0;k<=n+1;++k)
			rex[i][j]=(rex[i][j]+d[i][k]*o[k][j]%mod)%mod;
		return rex;
	}
}o;
void solve(ll x,ll y){
	Matrix t;
	for(int i=0;i<=n+1;++i){
		for(int j=0;j<=n+1;++j){
			if(l[i][j]<=x&&x<r[i][j])t[i][j]=1;
		}
	}
	t[0][0]=1;
	for(;y;y>>=1,t=t*t)if(y&1)o=o*t;
}
int main(){
	scanf("%d",&n);
	n++;
	int sj;
	scanf("%d",&sj);
	o[0][0]=1;
	for(int i=2;i<=n;++i){
		scanf("%d",&a[i]);
		p[i]=p[i-1]+a[i];
		mi[i]=min(mi[i-1],p[i]);
		ans=max(ans,p[i]-mi[i-1]);
	}
	printf("%lld ",ans+1);
	if(!ans){printf("%lld\n",abs(p[n]-1)%mod);return 0;}
	ma[n]=p[n];
	for(int i=n-1;i>=1;--i){
		ma[i]=max(p[i],ma[i+1]);
	}
	l[n+1][n+1]=mi[n];
	r[n+1][n+1]=ma[1]+2;
	for(int i=1;i<=n;++i){
		if(ma[i]-p[i-1]==ans&&i>1)l[0][i-1]=p[i-1]-1,r[0][i-1]=p[i-1];
		if(!a[i]&&i>1)continue;
		if(p[i]-mi[i-1]==ans)l[i][n+1]=p[i],r[i][n+1]=p[i]+1;
		for(int j=i;j<=n;++j){
			if(ma[j]-mi[i]!=ans)continue;
			if(!a[j])continue;
			if(i==j&&a[j]<0)continue;
			l[i][j]=max(min(p[i-1]+1,p[i]),min(p[j-1],p[j]-1));
			r[i][j]=min(max(p[i]+1,p[i-1]),max(p[j],p[j-1]-1));
		}
	}
	int num=0;
	for(int i=0;i<=n+1;++i){
		for(int j=i;j<=n+1;++j){
			c[++num]=l[i][j];
			c[++num]=r[i][j];
		}
	}
	sort(c+1,c+num+1);
	num=unique(c+1,c+num+1)-c-1;
	for(int i=1;i<num;++i){
		solve(c[i],c[i+1]-c[i]);
	}
	printf("%lld\n",o[0][n+1]);
	return 0;
}