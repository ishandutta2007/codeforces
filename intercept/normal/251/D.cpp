#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e5+9;
int n;
int id[69],b[M];
ll v[69];
ll a[M],p,w;
bitset<69>d[69],D,B;
void insert(ll x,int o){
	D.reset();
	for(int i=61;i>=0;--i){
		if(p>>i&1)continue;
		if(x>>i&1){
			if(v[i])x^=v[i],D^=d[i];
			else {
				D[i]=1;
				v[i]=x;
				d[i]=D;
				id[i]=o;
				break;
			}
		}
	}
}
ll get(){
	ll rex=0;
	for(int i=61;i>=0;--i){
		if(p>>i&1)continue;
		if(v[i]&&!(rex>>i&1))rex^=v[i];
	}
	return (p^((1ll<<62)-1))&rex;
}
void build(){
	for(int i=0;i<=61;++i)v[i]=0;
	for(int i=1;i<=n;++i)insert(a[i],i);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		p^=a[i];
	}
	build();
	w=get();
	for(int i=61;i>=0;--i){
		if(p>>i&1){
			p^=1ll<<i;
			build();
			ll x=get();
			if((w&x)==w)w=x;
			else p^=1ll<<i;
		}
	}
	build();
	ll rex=0;
	for(int i=61;i>=0;--i){
		if(p>>i&1)continue;
		if(v[i]&&!(rex>>i&1))rex^=v[i],B^=d[i];
	}
	for(int i=0;i<=61;++i)if(B[i])b[id[i]]=1;
	for(int i=1;i<=n;++i){
		printf(b[i]?"2 ":"1 ");
	}
	return 0;
}