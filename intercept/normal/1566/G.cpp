#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll R=4e9;
const int M=2e5+9;
int n,m,q,sz;
int rt[M],ls[M*90],rs[M*90],sum[M*90];
map<int,int>mp[M>>1];
int t[M];
ll val[M>>1];
struct P{
	ll v;int a,b;
	bool operator < (const P&o)const{
		return v==o.v?(a==o.a?b<o.b:a<o.a):v<o.v;
	}
};
set<P>s[M>>1];
void update(int &now,ll l,ll r,int x,int v){
	if(!now)now=++sz;
	sum[now]+=v;
	if(l==r)return;
	ll mid=l+r>>1;
	x<=mid?update(ls[now],l,mid,x,v):update(rs[now],mid+1,r,x,v);
}
ll query(int u,int v,int w,ll l,ll r,int x){
	if(l==r)return l;
	ll mid=l+r>>1;
	return (sum[ls[u]]+sum[ls[v]]-(l<=x&&mid>=x))<sum[ls[w]]?query(ls[u],ls[v],ls[w],l,mid,x):query(rs[u],rs[v],rs[w],mid+1,r,x);
}
ll kth(int now,ll l,ll r,int k){
	if(l==r)return l;
	ll mid=l+r>>1;
	return k<=sum[ls[now]]?kth(ls[now],l,mid,k):kth(rs[now],mid+1,r,k-sum[ls[now]]);
}
void push(int x,int y){
	for(t[x+=n-1]=y;x;x>>=1)t[x>>1]=val[t[x]]<val[t[x^1]]?t[x]:t[x^1];
}
void add(int u,int v,int w){
	if(u>v)swap(u,v);
	mp[u][v]=w;
	s[0].insert(P{w,u,v});
	s[u].insert(P{w,0,v});
	s[v].insert(P{w,0,u});
	update(rt[u],1,R,w,1);
	if(sum[rt[u]]>=3){
		val[u]=1ll*kth(rt[u],1,R,1)+kth(rt[u],1,R,2)+kth(rt[u],1,R,3);
		push(u,u);
	}
	update(rt[v],1,R,w,1);
	if(sum[rt[v]]>=3){
		val[v]=1ll*kth(rt[v],1,R,1)+kth(rt[v],1,R,2)+kth(rt[v],1,R,3);
		push(v,v);
	}
	update(rt[0],1,R,w,1);
}
void del(int u,int v){
	if(u>v)swap(u,v);
	int w=mp[u][v];
	mp[u].erase(v);
	s[0].erase(P{w,u,v});
	s[u].erase(P{w,0,v});
	s[v].erase(P{w,0,u});
	update(rt[u],1,R,w,-1);
	if(sum[rt[u]]>=3){
		val[u]=1ll*kth(rt[u],1,R,1)+kth(rt[u],1,R,2)+kth(rt[u],1,R,3);
		push(u,u);
	}
	else push(u,0);
	update(rt[v],1,R,w,-1);
	if(sum[rt[v]]>=3){
		val[v]=1ll*kth(rt[v],1,R,1)+kth(rt[v],1,R,2)+kth(rt[v],1,R,3);
		push(v,v);
	}
	else push(v,0);
	update(rt[0],1,R,w,-1);
}
ll ask(){
	P o=*s[0].begin();
	int u=o.a,v=o.b;
	ll x;
	auto itu=s[u].begin(),itv=s[v].begin();
	itu++;itv++;
	if((*itu).b!=(*itv).b)x=(*itu).v+(*itv).v;
	else x=min(kth(rt[u],1,R,2)+kth(rt[v],1,R,3),kth(rt[u],1,R,3)+kth(rt[v],1,R,2));
	return min({x,val[t[1]],query(rt[u],rt[v],rt[0],1,R,o.v)+o.v});
}
int main(){
	val[0]=4e9;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)s[i].insert(P{R,0,-i});
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	printf("%lld\n",ask());
	scanf("%d",&q);
	for(int i=1,o,u,v,w;i<=q;++i){
		scanf("%d%d%d",&o,&u,&v);
		if(o==0)del(u,v);
		else {
			scanf("%d",&w);
			add(u,v,w);
		}
		printf("%lld\n",ask());
	}
	return 0;
}
/*

*/