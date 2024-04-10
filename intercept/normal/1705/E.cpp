#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=4e5+9;
const int B=2e5+100;
int n,m;
int b[M],a[M];
struct Segment_tree{
    ll vis[M<<2],sum[M<<2];
    void pd(int now,int l,int r){
        ll &v=vis[now];
        if(v){
            int ls=now<<1,rs=now<<1|1,mid=l+r>>1;
            vis[ls]+=v;
            vis[rs]+=v;
            sum[ls]+=1ll*(mid-l+1)*v;
            sum[rs]+=1ll*(r-mid)*v;
            v=0;
        }
    }
    void pu(int now){
        sum[now]=sum[now<<1]+sum[now<<1|1];
    }
    void update(int now,int l,int r,int x,int y,int v){
        if(x>y)return;
        if(x<=l&&r<=y){
            vis[now]+=v;
            sum[now]+=1ll*(r-l+1)*v;
            return;
        }
        pd(now,l,r);
        int mid=l+r>>1;
        if(x<=mid)update(now<<1,l,mid,x,y,v);
        if(y>mid)update(now<<1|1,mid+1,r,x,y,v);
        pu(now);
    }
    int find1(int now,int l,int r){
    	if(l==r)return l;
    	int mid=l+r>>1;
    	pd(now,l,r);
    	if(sum[now<<1])return find1(now<<1,l,mid);
    	else return find1(now<<1|1,mid+1,r);
    }
    int query1(int now,int l,int r,int x,int y){
        if(x>y)return 0;
        if(x<=l&&r<=y){
            return sum[now]?find1(now,l,r):0;
        }
        pd(now,l,r);
        int mid=l+r>>1,rex=0;
        if(x<=mid)rex=query1(now<<1,l,mid,x,y);
        if(y>mid&&!rex)rex=query1(now<<1|1,mid+1,r,x,y);
        return rex;
    }
    int find0(int now,int l,int r){
    	if(l==r)return l;
    	int mid=l+r>>1;
    	pd(now,l,r);
    	if(sum[now<<1]<mid-l+1)return find0(now<<1,l,mid);
    	else return find0(now<<1|1,mid+1,r);
    }
    int query0(int now,int l,int r,int x,int y){
        if(x>y)return 0;
        if(x<=l&&r<=y){
            return (sum[now]<r-l+1)?find0(now,l,r):0;
        }
        pd(now,l,r);
        int mid=l+r>>1,rex=0;
        if(x<=mid)rex=query0(now<<1,l,mid,x,y);
        if(y>mid&&!rex)rex=query0(now<<1|1,mid+1,r,x,y);
        return rex;
    }
    int find(int now,int l,int r){
    	if(l==r)return l;
    	int mid=l+r>>1;
    	pd(now,l,r);
    	if(sum[now<<1|1])return find(now<<1|1,mid+1,r);
    	return find(now<<1,l,mid);
    }
}T;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<M;++i){
		b[i]+=b[i-1]/2;
		b[i-1]%=2;
	}
	for(int i=1;i<B;++i){
		T.update(1,1,B,i,i,b[i]);
	}
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		int l=T.query1(1,1,B,a[x],B);
		T.update(1,1,B,l,l,-1);
		if(l>a[x])T.update(1,1,B,a[x],l-1,1);
		a[x]=y;
		int r=T.query0(1,1,B,y,B);
		T.update(1,1,B,r,r,1);
		if(r>y)T.update(1,1,B,y,r-1,-1);
		cout<<T.find(1,1,B)<<endl;
	}
	return 0;
}
/*
5 2
2 2 2 4 5
2 3
5 3
*/