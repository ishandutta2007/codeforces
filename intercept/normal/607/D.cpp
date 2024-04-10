#include<bits/stdc++.h>
#define eb emplace_back
#define ll long long
using namespace std;
const int mod=1e9+7;
const int M=2e5+9;
int n,q,sz;
int a[M],b[M],L[M],R[M],d[M],p[M],va[M];
vector<int>g[M];
struct Segment_tree{
    ll vis[M<<2],sum[M<<2],val[M<<2];
    void pd(int now,int l,int r){
        ll &v=vis[now];
        if(v!=1){
            int ls=now<<1,rs=now<<1|1;
            vis[ls]=1ll*vis[ls]*v%mod;
            vis[rs]=1ll*vis[rs]*v%mod;
            sum[ls]=1ll*sum[ls]*v%mod;
            sum[rs]=1ll*sum[rs]*v%mod;
            val[ls]=1ll*val[ls]*v%mod;
            val[rs]=1ll*val[rs]*v%mod;
            v=1;
        }
    }
    void pu(int now){
        sum[now]=(sum[now<<1]+sum[now<<1|1])%mod;
    }
    void update(int now,int l,int r,int x,int y,int v){
        if(x>y)return;
        if(x<=l&&r<=y){
            vis[now]=1ll*vis[now]*v%mod;
            val[now]=1ll*val[now]*v%mod;
            sum[now]=1ll*sum[now]*v%mod;
            return;
        }
        pd(now,l,r);
        int mid=(l+r)>>1;
        if(x<=mid)update(now<<1,l,mid,x,y,v);
        if(y>mid)update(now<<1|1,mid+1,r,x,y,v);
        pu(now);
    }
    void update(int now,int l,int r,int x,int v){
        if(l==r){
            sum[now]=1ll*v*val[now]%mod;
            return;
        }
        pd(now,l,r);
        int mid=(l+r)>>1;
        if(x<=mid)update(now<<1,l,mid,x,v);
        else update(now<<1|1,mid+1,r,x,v);
        pu(now);
    }
    ll query(int now,int l,int r,int x,int y){
        if(x>y)return 0;
        if(x<=l&&r<=y){
            return sum[now];
        }
        pd(now,l,r);
        int mid=(l+r)>>1;
        ll rex=0;
        if(x<=mid)rex=(rex+query(now<<1,l,mid,x,y))%mod;
        if(y>mid)rex=(rex+query(now<<1|1,mid+1,r,x,y))%mod;
        return rex;
    }
    ll query(int now,int l,int r,int x){
    	if(x==0)return 1;
        if(l==r){
            return val[now];
        }
        pd(now,l,r);
        int mid=(l+r)>>1;
        if(x<=mid)return query(now<<1,l,mid,x);
        else return query(now<<1|1,mid+1,r,x);
    }
    void build(int now,int l,int r){
    	vis[now]=1;
		if(l==r){
			sum[now]=0;
			val[now]=1;
			return;
		}
		int mid=(l+r)>>1;
		build(now<<1,l,mid);
		build(now<<1|1,mid+1,r);
	}
}T;
void dfs(int u){
	L[u]=++sz;
	for(auto v:g[u])dfs(v);
	R[u]=sz;
}
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
    return rex;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a[++n]>>q;
	for(int i=1;i<=q;++i){
		int o;
		cin>>o;
		if(o==1){
			int fa;
			cin>>fa>>a[++n];
			p[n]=fa;
			va[i]=n;
			g[fa].eb(n);
		}
		else{
			cin>>b[i];
		}
	}
	dfs(1);
	for(int i=1;i<=n;++i)d[i]=1;
	T.build(1,1,n);
	T.update(1,1,n,1,a[1]);
	for(int i=1;i<=q;++i){
		if(va[i]){
			T.update(1,1,n,L[va[i]],a[va[i]]);
			T.update(1,1,n,L[p[va[i]]],R[p[va[i]]],kpow(d[p[va[i]]],mod-2));
			d[p[va[i]]]++;
			T.update(1,1,n,L[p[va[i]]],R[p[va[i]]],d[p[va[i]]]);
		}
		else{
			cout<<1ll*T.query(1,1,n,L[b[i]],R[b[i]])*kpow(T.query(1,1,n,L[p[b[i]]]),mod-2)%mod<<"\n";
		}
	}
}