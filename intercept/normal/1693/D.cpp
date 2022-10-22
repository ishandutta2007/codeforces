#include<bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n;
int p[M];
struct Segment_tree{
    int vis[M<<2][2],sum[M<<2][2];
    void pd(int now,int l,int r){
    	for(int o=0;o<2;++o){
    		int &v=vis[now][o];
	        if(v){
	            int ls=now<<1,rs=now<<1|1,mid=l+r>>1;
	            vis[ls][o]=v;
	            vis[rs][o]=v;
	            sum[ls][o]=v;
	            sum[rs][o]=v;
	            v=0;
	        }
    	}
    }
    void pu(int now){
        sum[now][0]=min(sum[now<<1][0],sum[now<<1|1][0]);
        sum[now][1]=max(sum[now<<1][1],sum[now<<1|1][1]);
    }
    void update(int now,int l,int r,int x,int y,int v,int o){
        if(x>y)return;
        if(x<=l&&r<=y){
            sum[now][o]=v;
            vis[now][o]=v;
            return;
        }
        pd(now,l,r);
        int mid=l+r>>1;
        if(x<=mid)update(now<<1,l,mid,x,y,v,o);
        if(y>mid)update(now<<1|1,mid+1,r,x,y,v,o);
        pu(now);
    }
    int query(int now,int l,int r,int x,int o){
        if(l==r){
            return sum[now][o];
        }
        pd(now,l,r);
        int mid=l+r>>1;
        if(x<=mid)return query(now<<1,l,mid,x,o);
        else return query(now<<1|1,mid+1,r,x,o);
    }
    int ask(int now,int l,int r,int x,int o){
    	if(l==r)return l;
    	int mid=l+r>>1;
    	if(o){
    		if(sum[now<<1][o]>x)return ask(now<<1,l,mid,x,o);
    		else return ask(now<<1|1,mid+1,r,x,o);
    	}
    	else{
    		if(sum[now<<1][o]<x)return ask(now<<1,l,mid,x,o);
    		else return ask(now<<1|1,mid+1,r,x,o);
    	}
    }
    void build(int now,int l,int r){
    	sum[now][0]=0;
    	sum[now][1]=n+1;
    	if(l==r)return;
    	int mid=l+r>>1;
    	build(now<<1,l,mid);
    	build(now<<1|1,mid+1,r);
    }
}T;
bool check(int x,int i){
	if(T.query(1,1,n,i,0)>x&&T.query(1,1,n,i,1)<x)return 1;
	return 0;
}
int main(){
	ll ans=1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	T.build(1,1,n);
	for(int i=2,j=1;i<=n;++i){
		int l=T.ask(1,1,n,p[i-1],0);
		int r=T.ask(1,1,n,p[i-1],1)-1;
		if(p[i]>p[i-1]){
			T.update(1,1,n,l,i-1,p[i-1],0);
			T.update(1,1,n,j,l-1,p[i-1],1);
		}
		else{
			T.update(1,1,n,l,r,p[i-1],0);
			T.update(1,1,n,j,l-1,p[i-1],1);
			T.update(1,1,n,r+1,i-1,p[i-1],1);
		}
		while(check(p[i],j)){
			T.update(1,1,n,j,j,n+1,0);
			T.update(1,1,n,j,j,0,1);
			j++;
		}
		ans+=i-j+1;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
1
6

3 3 4 1 3 3

3 4 1 3 3 3




*/