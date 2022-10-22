#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
using namespace std;
typedef long long ll;
const int N=4e5+7,inf=1e9+1;
struct node{
	mutable int l,r,v;
	bool operator<(node x)const{return r<x.r;}
};
using IT=set<node>::iterator;
int n,k,l,r,a[N];
ll ans,d;
vector<node>b[N];
set<node>s;
IT split(int x){
    IT it=s.lower_bound({0,x,0});
    if(it!=s.end()&&it->l==x)return it;
    int R=it->r;
    return it->r=x-1,s.insert({x,R,it->v}).first;
}
void chk(int lm){
	ll p=1,nw=0,su=0,ct=0,rs=0,S=0,T=0;
	memset(a,0,sizeof a);
	FOR(i,1,n){
		for(node k:b[i]){
			a[k.l]+=k.v,d=k.l-p+1,S+=1ll*k.l*k.v; 
			if(d>0)nw+=k.v,su+=d*k.v;
		}
		while(p<=i&&nw>=lm)su-=nw,nw-=a[p++];
		ct+=p-1,rs+=su,T+=S;
	}
	if(ct>=k)ans=T-rs-lm*(ct-k),l=lm;
	else r=lm;
}
signed main(){
	scanf("%d%d",&n,&k),s={{1,inf,0}};
	FOR(i,1,n){
		scanf("%d%d",&l,&r),--r;
		for(IT R=split(r+1),L=split(l),nx;L!=R;L=nx){
			if(L->v)b[i].push_back({L->v,0,L->l-1-L->r});
			nx=next(L),s.erase(L);
		}
		s.insert({l,r,i}),b[i].push_back({i,0,r-l+1});
	}
	for(l=0,r=inf;l<r-1;)chk((l+r)/2);
	printf("%lld",ans);
	return 0;
}