#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e6+9;
struct Segment_tree{
    int vis[M<<2][2],ma[M<<2][2];
    void pd(int now,int l,int r,int o){
        int &v=vis[now][o];
        if(v){
            int ls=now<<1,rs=now<<1|1,mid=(l+r)>>1;
            vis[ls][o]+=v;
            vis[rs][o]+=v;
            ma[ls][o]+=v;
            ma[rs][o]+=v;
            v=0;
        }
    }
    void pu(int now,int o){
        ma[now][o]=max(ma[now<<1][o],ma[now<<1|1][o]);
    }
    void update(int now,int l,int r,int x,int y,int v,int o){
        if(x>y)return;
        if(x<=l&&r<=y){
            vis[now][o]+=v;
            ma[now][o]+=v;
            return;
        }
        pd(now,l,r,o);
        int mid=(l+r)>>1;
        if(x<=mid)update(now<<1,l,mid,x,y,v,o);
        if(y>mid)update(now<<1|1,mid+1,r,x,y,v,o);
        pu(now,o);
    }
    int query(int now,int l,int r,int x,int y,int o){
        if(x>y)return 0;
        if(x<=l&&r<=y){
            return ma[now][o];
        }
        pd(now,l,r,o);
        int mid=(l+r)>>1;
        int rex=0;
        if(x<=mid)rex=max(rex,query(now<<1,l,mid,x,y,o));
        if(y>mid)rex=max(rex,query(now<<1|1,mid+1,r,x,y,o));
        return rex;
    }
}T;
int n,num;
int u[M],v[M],w[M],c[M],id[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>u[i]>>v[i]>>w[i];
		w[i]--;
		c[++num]=u[i];
		c[++num]=v[i];
	}
	sort(c+1,c+num+1);
	num=unique(c+1,c+num+1)-c-1;
	for(int i=1;i<=n;++i){
		id[i]=i;
		u[i]=lower_bound(c+1,c+num+1,u[i])-c;
		v[i]=lower_bound(c+1,c+num+1,v[i])-c;
	}
	sort(id+1,id+n+1,[&](const int&l,const int&r){return v[l]==v[r]?u[l]<u[r]:v[l]<v[r];});
	for(int o=1;o<=n;++o){
		int i=id[o];
		T.update(1,0,num,0,u[i]-1,1,w[i]^1);
		int x=T.query(1,0,num,v[i],v[i],w[i]),y=T.query(1,0,num,0,u[i]-1,w[i]^1);
		T.update(1,0,num,v[i],v[i],max(x,y)-x,w[i]);
	}
	cout<<max(T.query(1,0,num,0,num,0),T.query(1,0,num,0,num,1))<<"\n";
	return 0;
}