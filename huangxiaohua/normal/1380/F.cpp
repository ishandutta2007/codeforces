#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,n,m,t;
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
string a;
struct SB{
	ll a,b,c,d;
	SB(){a=b=c=d=0;}
	SB(ll NMSL1,ll NMSL2,ll NMSL3,ll NMSL4){
		a=NMSL1;b=NMSL2;c=NMSL3;d=NMSL4;
	}
	SB operator*(const SB x){
		return (SB){su(a*x.a%M,b*x.c%M),su(a*x.b%M,b*x.d%M),su(c*x.a%M,d*x.c%M),su(c*x.b%M,d*x.d%M)};
	}
};
struct JB{
	#define md ((l+r)>>1)
	#define ls (id<<1)
	#define rs (ls+1)
	SB f[2005000];
	void fuck(int id,int x){
		int y=0;if(a[x-1]==1)y=9-a[x];
		f[id]={a[x]+1,1,y,0};return;
	}
	void build(int id,int l,int r){
		if(l==r){fuck(id,l);return;}
		build(ls,l,md);build(rs,md+1,r);
		f[id]=f[ls]*f[rs];
	}
	void add(int id,int l,int r,int x){
		if(l==r){fuck(id,l);return;}
		if(x<=md)add(ls,l,md,x);
		else add(rs,md+1,r,x);
		f[id]=f[ls]*f[rs];
	}
}jb;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>t>>a;
	a="0"+a;for(auto &i:a)i-='0';
	jb.build(1,1,n);
	while(t--){
		cin>>i>>j;a[i]=j;
		jb.add(1,1,n,i);
		if(i!=n)jb.add(1,1,n,i+1);
		cout<<jb.f[1].a<<'\n';
	}
}