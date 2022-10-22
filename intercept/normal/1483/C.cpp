#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=3e5+9;
const ll INF=-1ll<<60;
int n;
int h[M],b[M],s[M];
ll f[M],ma[M<<2],val[M];
void build(int num,int l,int r){
	ma[num]=INF;
	if(l==r)return;
	int mid=l+r>>1;
	build(num<<1,l,mid);
	build(num<<1|1,mid+1,r);
}
void update(int num,int l,int r,int x,ll v){
	if(l==r){ma[num]=v;return;}
	int mid=l+r>>1;
	if(x<=mid)update(num<<1,l,mid,x,v);
	else update(num<<1|1,mid+1,r,x,v);
	ma[num]=max(ma[num<<1],ma[num<<1|1]); 
}
ll query(int num,int l,int r,int x,int y){
	if(x<=l&&r<=y)return ma[num];
	int mid=l+r>>1;ll ans=INF;
	if(x<=mid)ans=max(ans,query(num<<1,l,mid,x,y));
	if(y>mid)ans=max(ans,query(num<<1|1,mid+1,r,x,y));
	return ans;
}
int main(){
	int top=0;
	scanf("%d",&n);
	build(1,1,n);
	for(int i=1;i<=n;++i)scanf("%d",&h[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	val[0]=INF;
	for(int i=1;i<=n;++i){
		f[i]=INF;
		while(top&&h[s[top]]>h[i]){
			f[i]=max(f[i],query(1,1,n,s[top-1]+1,s[top])+b[i]);
			top--;
		}
		f[i]=max(f[i],f[i-1]+b[i]);
		if(top)f[i]=max(f[i],val[top]);
		else f[i]=max(f[i],1ll*b[i]);
		update(1,1,n,i,f[i]);
		s[++top]=i;
		val[top]=max(val[top-1],f[i]);
		if(s[top-1]+1<=s[top-1])val[top]=max(val[top],query(1,1,n,s[top-1]+1,s[top]-1)+b[i]);
	}
	printf("%lld\n",f[n]);
	return 0;
}