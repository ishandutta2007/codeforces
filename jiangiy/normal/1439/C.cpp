#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=200010,INF=1e9+10;
struct node{
	int mi,mi2,mic,tg;
	LL sum;
}
f[600000];
void set(int x,int l,int r,int v){
	if(v<f[x].mi)return;
	assert(v<f[x].mi2);
	f[x].sum+=(LL)(v-f[x].mi)*f[x].mic;
	f[x].mi=f[x].tg=v;
}
void pd(int x,int l,int r,int t){
	if(f[x].tg){
		set(x<<1,l,t,f[x].tg);
		set(x<<1|1,t+1,r,f[x].tg);
		f[x].tg=0;
	}
}
void merge(node&a,node&b,node&r){
	r.sum=a.sum+b.sum;
	if(a.mi<b.mi)r.mi=a.mi,r.mic=a.mic,r.mi2=std::min(a.mi2,b.mi);
	else if(a.mi>b.mi)r.mi=b.mi,r.mic=b.mic,r.mi2=std::min(a.mi,b.mi2);
	else r.mi=a.mi,r.mic=a.mic+b.mic,r.mi2=std::min(a.mi2,b.mi2);
}
void pu(int x){
	merge(f[x<<1],f[x<<1|1],f[x]);
}
void mod(int x,int l,int r,int ql,int qr,int v){
	if(v<f[x].mi)return;
	if(l>=ql&&r<=qr){
		if(v<f[x].mi2)return set(x,l,r,v);
		if(l==r){
			f[x].mi=f[x].sum=v;
			f[x].mic=1;
			f[x].mi2=INF;
			return;
		}
	}
	int t=(l+r)>>1;
	pd(x,l,r,t);
	if(ql<=t)mod(x<<1,l,t,ql,qr,v);
	if(qr>t)mod(x<<1|1,t+1,r,ql,qr,v);
	pu(x);
}
node query(int x,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)return f[x];
	int t=(l+r)>>1;
	pd(x,l,r,t);
	if(qr<=t)return query(x<<1,l,t,ql,qr);
	if(ql>t)return query(x<<1|1,t+1,r,ql,qr);
	node a=query(x<<1,l,t,ql,qr),b=query(x<<1|1,t+1,r,ql,qr),res;
	merge(a,b,res);
	return res;
}
int query2(int x,int l,int r,int v){
	if(l==r)return l;
	int t=(l+r)>>1;
	pd(x,l,r,t);
	if(f[x<<1].mi<=v)return query2(x<<1,l,t,v);
	return query2(x<<1|1,t+1,r,v);
}
int query4(int x,int l,int r,LL sum){
	if(f[x].sum<=sum)return r;
	if(l==r)return l-1;
	int t=(l+r)>>1;
	pd(x,l,r,t);
	if(f[x<<1].sum>=sum)return query4(x<<1,l,t,sum);
	return query4(x<<1|1,t+1,r,sum-f[x<<1].sum);
}
int n,m,s[N];
int query3(int v){
	if(f[1].mi>v)return n+1;
	return query2(1,1,n,v);
}
void build(int x,int l,int r){
	if(l==r){
		f[x].mi=f[x].sum=s[l];
		f[x].mic=1;
		f[x].mi2=INF;
	}
	else{
		int t=(l+r)>>1;
		build(x<<1,l,t);
		build(x<<1|1,t+1,r);
		pu(x);
	}
}
PI query_next(int x,int y,int&ans){
	x=std::max(query3(y),x);
	if(x>n)return MP(n+1,y);
	LL pre=0;
	if(x>1)pre=query(1,1,n,1,x-1).sum;
	int lst=query4(1,1,n,pre+y);
	ans+=lst-x+1;
	return MP(lst+1,y-query(1,1,n,x,lst).sum);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	build(1,1,n);
	while(m--){
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)mod(1,1,n,1,x,y);
		else{
			int ans=0;
			while(1){
				PI nxt=query_next(x,y,ans);
				if(nxt.fi>=n+1)break;
				x=nxt.fi,y=nxt.se;
			}
			printf("%d\n",ans);
		}
	}
}