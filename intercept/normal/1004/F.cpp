#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,m,val;
int a[M],p[21],pp[21];
set<int>s[20];
struct Segment_tree{
    ll vis[M<<2],sum[M<<2],ma[M<<2];
    void pd(int now,int l,int r){
        ll &v=vis[now];
        if(v!=-1){
            int ls=now<<1,rs=now<<1|1,mid=(l+r)>>1;
            vis[ls]=v;
            vis[rs]=v;
            sum[ls]=1ll*(mid-l+1)*v;
            sum[rs]=1ll*(r-mid)*v;
            ma[ls]=v;
            ma[rs]=v;
            v=-1;
        }
    }
    void pu(int now){
        sum[now]=sum[now<<1]+sum[now<<1|1];
        ma[now]=max(ma[now<<1],ma[now<<1|1]);
    }
    void update(int now,int l,int r,int x,int y,int v){
        if(x>y)return;
        if(x<=l&&r<=y){
            vis[now]=v;
            ma[now]=v;
            sum[now]=1ll*(r-l+1)*v;
            return;
        }
        pd(now,l,r);
        int mid=(l+r)>>1;
        if(x<=mid)update(now<<1,l,mid,x,y,v);
        if(y>mid)update(now<<1|1,mid+1,r,x,y,v);
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
        if(x<=mid)rex+=query(now<<1,l,mid,x,y);
        if(y>mid)rex+=query(now<<1|1,mid+1,r,x,y);
        return rex;
    }
    int ask(int now,int l,int r,int x){
    	if(l==r)return l;
    	pd(now,l,r);
    	int mid=(l+r)>>1;
    	if(ma[now<<1]>=x)return ask(now<<1,l,mid,x);
    	else return ask(now<<1|1,mid+1,r,x);
    }
    void build(int now,int l,int r){
    	vis[now]=-1;
    	if(l==r)return;
    	int mid=(l+r)>>1;
    	build(now<<1,l,mid);
    	build(now<<1|1,mid+1,r);
    }
}T;
int get(int x){
	for(int j=0;j<20;++j){
		p[j]=*prev(s[j].upper_bound(x));
	}
	sort(p,p+20);
	for(int j=19,t=0;j>=0;--j){
		t|=a[p[j]];
		if(t>=val)return p[j];
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>val;
	for(int j=0;j<20;++j)s[j].insert(0),s[j].insert(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		for(int j=0;j<20;++j){
			if(a[i]>>j&1)s[j].insert(i);
		}
	}
	T.build(1,1,n+1);
	for(int i=1;i<=n;++i){
		T.update(1,1,n+1,i,i,get(i));
	}
	T.update(1,1,n+1,n+1,n+1,n+1);
	for(int i=1;i<=m;++i){
		int o,x,y;
		cin>>o>>x>>y;;
		if(o==1){
			for(int j=0;j<20;++j){
				if(a[x]>>j&1)s[j].erase(x);
			}
			a[x]=y;
			for(int j=0;j<20;++j){
				if(a[x]>>j&1)s[j].insert(x);
			}
			for(int j=0;j<20;++j){
				pp[j]=*s[j].lower_bound(x);
			}
			sort(pp,pp+20);
			pp[20]=n+1;
			T.update(1,1,n+1,x,pp[0]-1,get(x));
			int z=T.ask(1,1,n+1,x+1)-1;
			for(int j=0;j<20;++j){
				if(pp[j+1]==pp[j])continue;
				if(pp[j]<=z)T.update(1,1,n+1,pp[j],min(pp[j+1]-1,z),get(pp[j]));
				else break;
			}
		}
		else {
			int z=T.ask(1,1,n+1,x);
			if(z>y){
				cout<<"0\n";
				continue;
			}
			cout<<T.query(1,1,n+1,z,y)-1ll*(x-1)*(y-z+1)<<"\n";
		}
	}
	return 0;
}
/*
4 2 7
7 3 6 1
1 3 0
2 1 4

*/