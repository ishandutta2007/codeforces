#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
//typedef unsigned int uint;
#define N 4000000050ll
#define M 2000000010ll
gp_hash_table<ll, int>  id;
set<ll> s;
int f[1005000],f2[1005000],it;
void add1(int x,int y){assert(x>=0);for(;x<=it;x+=(-x&x)){f[x]+=y;}}
void add2(int x,int y){assert(x>=0);for(;x;x-=(-x&x)){f2[x]+=y;}}
int get1(int x,int y=0){assert(x>=0);for(;x;x-=(-x&x)){y+=f[x];}return y;}
int get2(int x,int y=0){assert(x>=0);for(;x<=it;x+=(-x&x)){y+=f2[x];}return y;}

struct sb1{
	ll l,r,b;
	bool operator<(const sb1 x)const{return l<x.l;}
}s1[100500];

struct sb2{
	ll id,c,p;
	bool operator<(const sb2 x)const{return c<x.c;}
}s2[100500];
int i,j,k,n,m,t,res[100500];
int cnt;
priority_queue<sb1> q;

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline ll read()
{
    char c=getchar();ll x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main(){
	n=read();m=read();
	for(i=1;i<=n;i++)s1[i].l=read();
	for(i=1;i<=n;i++)s1[i].r=read();
	for(i=1;i<=n;i++)s1[i].b=read();
	for(i=1;i<=m;i++)s2[i].c=read();
	for(i=1;i<=m;i++)s2[i].p=read();
	for(i=1;i<=m;i++)s2[i].id=i;
	sort(s1+1,s1+n+1);
	sort(s2+1,s2+m+1);
	j=1;
	for(i=1;i<=m;i++){
		s.insert((ll)s2[i].p+(1000000000-s2[i].c)+M-1);
		s.insert((ll)s2[i].p-(1000000000-s2[i].c)+M+1);
	}
	for(i=1;i<=n;i++){
		auto [l,r,z]=s1[i];
		s.insert((ll)z+(1000000000-l)+M);
		s.insert((ll)z-(1000000000-l)+M);
	}
	for(auto i:s){id[i]=++it;}
	for(i=1;i<=m;i++){
		for(;j<=n;j++){
			if(s1[j].l>s2[i].c)break;
			auto [l,r,z]=s1[j];
			q.push({-r,l,z});
			add1(id[(ll)z+(1000000000-l)+M],1);
			add2(id[(ll)z-(1000000000-l)+M],1);
			cnt++;
		}
		while(!q.empty()){
			auto [r,l,z]=q.top();r=-r;
			if(r>=s2[i].c)break;
			q.pop();
			add1(id[(ll)z+(1000000000-l)+M],-1);
			add2(id[(ll)z-(1000000000-l)+M],-1);
			cnt--;
		}
		res[s2[i].id]=cnt;
		res[s2[i].id]-=get1(id[(ll)s2[i].p+(1000000000-s2[i].c)+M-1]);
		res[s2[i].id]-=get2(id[(ll)s2[i].p-(1000000000-s2[i].c)+M+1]);
	}
	for(i=1;i<=m;i++){
		printf("%d ",res[i]);
	}
}