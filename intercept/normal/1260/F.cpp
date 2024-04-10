#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int mod=1e9+7;
const int M=100009;
const int N=1e5;
int n,sum=1;
int siz[M],son[M],dep[M];
vector<int>g[M],p;
int l[M],r[M],inv[M];
void dfs(int u,int fa){
	siz[u]=1;
	dep[u]=dep[fa]+1;
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u);
			siz[u]+=siz[v];
			if(siz[son[u]]<siz[v])son[u]=v;
		}
	}
}
struct Segment_tree{
    pii vis[M<<2],sum[M<<2];
    void add(pii &a,pii b){
    	a.fi+=b.fi;
    	a.se+=b.se;
    	if(a.fi>=mod)a.fi-=mod;
    	if(a.se>=mod)a.se-=mod;
    }
    void pd(int now,int l,int r){
        auto &v=vis[now];
        if(v!=make_pair(0,0)){
        	int ls=now<<1,rs=now<<1|1,mid=(l+r)>>1;
	        add(vis[ls],v);
	        add(vis[rs],v);
	        add(sum[ls],make_pair(1ll*(mid-l+1)*v.fi%mod,1ll*(mid-l+1)*v.se%mod));
	        add(sum[rs],make_pair(1ll*(r-mid)*v.fi%mod,1ll*(r-mid)*v.se%mod));
	        v=make_pair(0,0);
        }
    }
    void pu(int now){
        sum[now].fi=(sum[now<<1].fi+sum[now<<1|1].fi)%mod;
        sum[now].se=(sum[now<<1].se+sum[now<<1|1].se)%mod;
    }
    void update(int now,int l,int r,int x,int y,pii v){
        if(x>y)return;
        if(x<=l&&r<=y){
            add(vis[now],v);
            add(sum[now],make_pair(1ll*(r-l+1)*v.fi%mod,1ll*(r-l+1)*v.se%mod));
            return;
        }
        pd(now,l,r);
        int mid=(l+r)>>1;
        if(x<=mid)update(now<<1,l,mid,x,y,v);
        if(y>mid)update(now<<1|1,mid+1,r,x,y,v);
        pu(now);
    }
    pii query(int now,int l,int r,int x,int y){
        if(x>y)return make_pair(0,0);
        if(x<=l&&r<=y){
            return sum[now];
        }
        pd(now,l,r);
        int mid=(l+r)>>1;
        pii rex=make_pair(0,0);
        if(x<=mid)add(rex,query(now<<1,l,mid,x,y));
        if(y>mid)add(rex,query(now<<1|1,mid+1,r,x,y));
        return rex;
    }
}T;
void add(int u,int fa){
	p.eb(u);
	for(auto v:g[u]){
		if(v!=fa)add(v,u);
	}
}
int ans=0;
void solve(int u,int fa){
	for(auto v:g[u]){
		if(v!=fa&&v!=son[u]){
			solve(v,u);
			p.clear();
			add(v,u);
			for(auto o:p){
				T.update(1,1,N,l[o],r[o],make_pair(mod-1ll*dep[o]*sum%mod*inv[r[o]-l[o]+1]%mod,mod-inv[r[o]-l[o]+1]));
			}
		}
	}
	if(son[u])solve(son[u],u);
	for(auto v:g[u]){
		if(v!=fa&&v!=son[u]){
			p.clear();
			add(v,u);
			for(auto o:p){
				auto t=T.query(1,1,N,l[o],r[o]);
				ans=(ans+1ll*(dep[o]+mod-2*dep[u])*sum%mod*inv[r[o]-l[o]+1]%mod*t.se%mod)%mod;
				ans=(ans+1ll*inv[r[o]-l[o]+1]*t.fi%mod)%mod;
			}
			for(auto o:p){
				T.update(1,1,N,l[o],r[o],make_pair(1ll*dep[o]*sum%mod*inv[r[o]-l[o]+1]%mod,inv[r[o]-l[o]+1]));
			}
		}
	}
	int o=u;
	auto t=T.query(1,1,N,l[o],r[o]);
	ans=(ans+1ll*(dep[o]+mod-2*dep[u])*sum%mod*inv[r[o]-l[o]+1]%mod*t.se%mod)%mod;
	ans=(ans+1ll*inv[r[o]-l[o]+1]*t.fi%mod)%mod;
	T.update(1,1,N,l[o],r[o],make_pair(1ll*dep[o]*sum%mod*inv[r[o]-l[o]+1]%mod,inv[r[o]-l[o]+1]));
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	inv[0]=inv[1]=1;
	for(int i=2;i<M;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;++i)cin>>l[i]>>r[i],sum=1ll*sum*(r[i]-l[i]+1)%mod;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}	
	dfs(1,0);
	solve(1,0);
	cout<<ans<<"\n";
	return 0;
}