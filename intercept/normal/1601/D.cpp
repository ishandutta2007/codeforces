#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=2e6+9;
int n,m;
struct Segment_tree{
    ll vis[M<<2],sum[M<<2];
    void pd(int now,int l,int r){
        ll &v=vis[now];
        if(v){
            int ls=now<<1,rs=now<<1|1;
            vis[ls]+=v;
            vis[rs]+=v;
            sum[ls]+=v;
            sum[rs]+=v;
            v=0;
        }
    }
    void pu(int now){
        sum[now]=max(sum[now<<1],sum[now<<1|1]);
    }
    void update(int now,int l,int r,int x,int y,int v){
        if(x>y)return;
        if(x<=l&&r<=y){
            vis[now]+=v;
            sum[now]+=v;
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
        ll rex=-1e6;
        if(x<=mid)rex=max(rex,query(now<<1,l,mid,x,y));
        if(y>mid)rex=max(rex,query(now<<1|1,mid+1,r,x,y));
        return rex;
    }
}T;
int num,c[M<<1];
int s[M],p[M],b[M],dp[M];
vector<int>g[M],t[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	c[++num]=m;
	for(int i=1;i<=n;++i)cin>>s[i]>>p[i],c[++num]=s[i],c[++num]=p[i];
	sort(c+1,c+num+1);
	num=unique(c+1,c+num+1)-c-1;
	m=lower_bound(c+1,c+num+1,m)-c;
	for(int i=1;i<=n;++i){
		s[i]=lower_bound(c+1,c+num+1,s[i])-c;
		p[i]=lower_bound(c+1,c+num+1,p[i])-c;
		if(s[i]>=m&&p[i]<=m)dp[m]++;
		if(s[i]>=p[i]){
			b[p[i]]++;
			t[s[i]].eb(p[i]);
		}
		g[p[i]].eb(s[i]);
	}
	int ans=0;
	T.update(1,1,num,1,m-1,-n);
	for(int i=m;i<=num;++i){
		T.update(1,1,num,1,i-1,b[i]);
		for(auto o:g[i]){
			dp[i]=max(1ll*dp[i],T.query(1,1,num,1,o)+(o<i));
			ans=max(ans,dp[i]);
		}
		for(auto o:t[i]){
			T.update(1,1,num,1,o-1,-1);
		}
		T.update(1,1,num,i,i,dp[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
10 4
6 11
1 5
2 8
9 13
20 19
3 16
15 17
10 14
12 18
7 21

*/