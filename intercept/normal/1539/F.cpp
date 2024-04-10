#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+9;
int n;
int a[M],ans[M],id[M];
int vis[M<<2],ma[M<<2],mi[M<<2];
void pu(int num){
	ma[num]=max(ma[num<<1],ma[num<<1|1]);
	mi[num]=min(mi[num<<1],mi[num<<1|1]);
}
void pd(int num){
	if(vis[num]){
		int k=vis[num];
		ma[num<<1]+=k;
		mi[num<<1]+=k;
		vis[num<<1]+=k;
		ma[num<<1|1]+=k;
		mi[num<<1|1]+=k;
		vis[num<<1|1]+=k;
		vis[num]=0;
	}
}
void update(int num,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){
		vis[num]+=v;
		ma[num]+=v;
		mi[num]+=v;
		return;
	}
	pd(num);
	int mid=l+r>>1;
	if(x<=mid)update(num<<1,l,mid,x,y,v);
	if(y>mid)update(num<<1|1,mid+1,r,x,y,v);
	pu(num);
}
int query(int num,int l,int r,int x,int y,bool o){
	if(x<=l&&r<=y){
		return o?ma[num]:mi[num];
	}
	pd(num);
	int mid=l+r>>1,ans=o?-1e9:1e9;
	if(x<=mid){
		if(o)ans=max(ans,query(num<<1,l,mid,x,y,o));
		else ans=min(ans,query(num<<1,l,mid,x,y,o));
	}
	if(y>mid){
		if(o)ans=max(ans,query(num<<1|1,mid+1,r,x,y,o));
		else ans=min(ans,query(num<<1|1,mid+1,r,x,y,o));
	}
	return ans;
}
void build(int num,int l,int r){
	if(l==r){
		ma[num]=mi[num]=-l;
		return;
	}
	int mid=l+r>>1;
	build(num<<1,l,mid);
	build(num<<1|1,mid+1,r);
	pu(num);
}
vector<int>b[M];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[a[i]].push_back(i);
	build(1,0,n);
	for(int o=1;o<=n;++o){
		for(auto i:b[o]){
			update(1,0,n,i,n,2);
			int x=(query(1,0,n,i,n,1)-query(1,0,n,0,i-1,0)-1)/2;
			int y=(query(1,0,n,0,i-1,1)-query(1,0,n,i,n,0)+2)/2;
			update(1,0,n,i,n,-2);
			ans[i]=max(x,y);
		}
		for(auto i:b[o])update(1,0,n,i,n,2);
		for(auto i:b[o]){
			int x=(query(1,0,n,i,n,1)-query(1,0,n,0,i-1,0)-1)/2;
			int y=(query(1,0,n,0,i-1,1)-query(1,0,n,i,n,0)+2)/2;
			ans[i]=max({ans[i],x,y});
		}
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}