#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=2e5+9;
struct Segment_tree{
    ll vis[M<<2],sum[M<<2],val[M<<2];
    void pd(int now,int l,int r){
        ll &v=vis[now];
        if(v){
            int ls=now<<1,rs=now<<1|1,mid=l+r>>1;
            vis[ls]+=v;
            vis[rs]+=v;
            sum[ls]+=1ll*val[ls]*v;
            sum[rs]+=1ll*val[rs]*v;
            v=0;
        }
    }
    void pu(int now){
        sum[now]=sum[now<<1]+sum[now<<1|1];
        val[now]=val[now<<1]+val[now<<1|1];
    }
    void update(int now,int l,int r,int x,int y,int v){
        if(x>y)return;
        if(x<=l&&r<=y){
            vis[now]+=v;
            sum[now]+=1ll*val[now]*v;
            return;
        }
        pd(now,l,r);
        int mid=l+r>>1;
        if(x<=mid)update(now<<1,l,mid,x,y,v);
        if(y>mid)update(now<<1|1,mid+1,r,x,y,v);
        pu(now);
    }
    void add(int now,int l,int r,int x,int v){
        if(l==r){
            val[now]+=v;
            sum[now]+=vis[now]*v;
            return;
        }
        pd(now,l,r);
        int mid=l+r>>1;
        if(x<=mid)add(now<<1,l,mid,x,v);
        else add(now<<1|1,mid+1,r,x,v);
        pu(now);
    }
    ll ask(int now,int l,int r,int x,int y){
    	if(x>y)return 0;
        if(x<=l&&r<=y){
            return val[now];
        }
        pd(now,l,r);
        int mid=l+r>>1;
        ll rex=0;
        if(x<=mid)rex+=ask(now<<1,l,mid,x,y);
        if(y>mid)rex+=ask(now<<1|1,mid+1,r,x,y);
        return rex;
    }
    ll query(int now,int l,int r,int x,int y){
        if(x>y)return 0;
        if(x<=l&&r<=y){
            return sum[now];
        }
        pd(now,l,r);
        int mid=l+r>>1;
        ll rex=0;
        if(x<=mid)rex+=query(now<<1,l,mid,x,y);
        if(y>mid)rex+=query(now<<1|1,mid+1,r,x,y);
        return rex;
    }
}b;
int n=2e5;
int q,d;
set<int>s;
ll ans=0;
void add(int x){
	s.insert(x);
	ll r=b.ask(1,1,n,x+1,min(x+d,n)),l=b.ask(1,1,n,max(x-d,1),x-1);
	ans+=b.query(1,1,n,max(x-d,1),x-1)+(r-1)*r/2;
	b.add(1,1,n,x,1);
	b.update(1,1,n,max(x-d,1),x-1,1);
}
void era(int x){
	s.erase(x);
	ll r=b.ask(1,1,n,x+1,min(x+d,n)),l=b.ask(1,1,n,max(x-d,1),x-1);
	ans-=b.query(1,1,n,max(x-d,1),x-1)-l+(r-1)*r/2;
	b.add(1,1,n,x,-1);
	b.update(1,1,n,max(x-d,1),x-1,-1);
}
int main(){
	scanf("%d%d",&q,&d);
	for(int i=1;i<=q;++i){
		int x;
		scanf("%d",&x);
		if(!s.count(x)){
			add(x);
		}
		else era(x);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4 5
8 5 5 2
*/