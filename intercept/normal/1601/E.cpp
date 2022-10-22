#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;
const int M=3e5+9;
int n,m,k;
int a[M],f[M][23],mi[M<<2],vis[M<<2];
ll sum[M<<2],ans[M];
vector<pii>q[M];
int ask(int l,int r){
	int p=log2(r-l+1);
	return min(f[l][p],f[r-(1<<p)+1][p]);
}
void pu(int now){
	mi[now]=min(mi[now<<1],mi[now<<1|1]);
	sum[now]=sum[now<<1]+sum[now<<1|1];
}
void pd(int now,int l,int r){
	if(vis[now]){
		int &v=vis[now],mid=l+r>>1;
		vis[now<<1]=vis[now<<1|1]=mi[now<<1]=mi[now<<1|1]=v;
		sum[now<<1]=1ll*(mid-l+1)*v;
		sum[now<<1|1]=1ll*(r-mid)*v;
		v=0;
	}
}
void update(int now,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){
		mi[now]=v;
		sum[now]=1ll*(r-l+1)*v;
		vis[now]=v;
		return;
	}
	pd(now,l,r);
	int mid=l+r>>1;
	if(x<=mid)update(now<<1,l,mid,x,y,v);
	if(y>mid)update(now<<1|1,mid+1,r,x,y,v);
	pu(now);
}
void change(int now,int l,int r,int v){
	if(mi[now]>v){
		mi[now]=v;
		sum[now]=1ll*(r-l+1)*v;
		vis[now]=v;
		return;
	}
	if(l==r)return;
	pd(now,l,r);
	int mid=l+r>>1;
	if(mi[now<<1]>v)change(now<<1|1,mid+1,r,v);
	change(now<<1,l,mid,v);
	pu(now);
}
ll query(int now,int l,int r,int x,int y){
	if(x<=l&&r<=y)return sum[now];
	int mid=l+r>>1;ll s=0;
	pd(now,l,r);
	if(x<=mid)s+=query(now<<1,l,mid,x,y);
	if(y>mid)s+=query(now<<1|1,mid+1,r,x,y);
	return s;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		f[i][0]=a[i];
	}
	for(int j=1;j<=20;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1,l,r;i<=m;++i){
		scanf("%d%d",&l,&r);
		r=(r-l)/k;
		q[l].emplace_back(r,i);
	}
	for(int p=n;p>n-k;--p){
		int R=(p-1)/k+1;
		update(1,1,R,1,R,(int)2e9);
		for(int id=R,i=p;id;--id,i-=k){
			if(i+k<=n)change(1,1,R,ask(i,i+k));
			update(1,1,R,1,id,(int)2e9);
			update(1,1,R,id,id,a[i]);
			for(auto o:q[i]){
				ans[o.se]=query(1,1,R,id,id+o.fi);
			}
		}
	}
	for(int i=1;i<=m;++i)printf("%lld\n",ans[i]);
	return 0;
}