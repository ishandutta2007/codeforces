#include<bits/stdc++.h>
typedef long long ll;
const int N=3e5+5,M=3e5+5;
int n,m;
ll x[N],p[M];
ll d;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%I64d",&x[i]);
	}
	for(int i=1;i<=m;++i){
		scanf("%I64d",&p[i]);
	}
	for(int i=1;i<n;++i){
		d=gcd(d,x[i+1]-x[i]);
	}
	for(int i=1;i<=m;++i){
		if(!(d%p[i])){
			puts("YES");
			printf("%I64d %d\n",x[1],i);
			return 0;
		}
	}
	puts("NO");
	return 0;
}