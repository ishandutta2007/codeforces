//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=105,maxm=1e5+5;
int n,m;
ll a[maxn],b[maxm];
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct Data{int num;ll s,f;};
Data t[4*maxm];
ll mn[4*maxm],laz[4*maxm];
inline Data merge(Data a,Data b){
	Data res;
	res.num=a.num+b.num;res.s=a.s+b.s;
	res.f=a.f+a.s*b.num+b.f;
	return res;
}
void pushup(int k){
	t[k]=merge(t[k<<1],t[k<<1|1]);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
	return ;
}
void build(int k,int l,int r){
	if(l==r){t[k]=(Data){1,b[l],b[l]};mn[k]=b[l];return ;}
	int mid=l+((r-l)>>1);
	build(k<<1,l,mid),build(k<<1|1,mid+1,r);
	pushup(k);
	return ;
}
void add_laz(int k,ll v){
	laz[k]+=v;mn[k]+=v;t[k].s+=v*t[k].num;
	t[k].f+=1ll*t[k].num*(t[k].num+1)/2*v;
	return ;
}
void pushdown(int k){
	if(!laz[k])return ;
	add_laz(k<<1,laz[k]),add_laz(k<<1|1,laz[k]);
	laz[k]=0;
	return ;
}
void modify(int k,int l,int r,int x,int y,int v){
	if(l>y||r<x)return ;
	if(l>=x&&r<=y){add_laz(k,v);return ;}
	int mid=l+((r-l)>>1);
	pushdown(k);
	modify(k<<1,l,mid,x,y,v);
	modify(k<<1|1,mid+1,r,x,y,v);
	pushup(k);
	return ;
}
int query(int k,int l,int r,ll v){
	if(l==r)return l;
	int mid=l+((r-l)>>1);
	pushdown(k);
	if(mn[k<<1|1]<=v)return query(k<<1|1,mid+1,r,v);
	return query(k<<1,l,mid,v);
}
Data query(int k,int l,int r,int x,int y){
	if(l>y||r<x)return (Data){0,0,0};
	if(l>=x&&r<=y)return t[k];
	int mid=l+((r-l)>>1);
	pushdown(k);
	return merge(query(k<<1,l,mid,x,y),query(k<<1|1,mid+1,r,x,y));
}
void solve(){
	int op,k,d;
	op=read();k=read();d=read();
	if(op==1)for(int i=n-k+1;i<=n;i++)a[i]+=d;
	else{modify(1,2,m,m-k+1,m,d);if(k==m)b[1]+=d;if(k>=m-1)b[2]+=d;}
	int lst=1;Data res={1,a[1]+b[1],a[1]+b[1]};
	for(int i=2;i<=n;i++){
		int p=(a[i]<b[2])?1:query(1,2,m,a[i]);
		res=merge(res,query(1,2,m,lst+1,p));lst=p;
		res=merge(res,(Data){1,a[i],a[i]});
	}
	res=merge(res,query(1,2,m,lst+1,m));
	printf("%lld\n",res.f);
	return ;
}
int main(){
    int q;
	n=read();m=read();q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=n;i>=1;i--)a[i]-=a[i-1];
	for(int i=1;i<=m;i++)b[i]=read();
	for(int i=m;i>=1;i--)b[i]-=b[i-1];
	build(1,2,m);
	while(q--)solve();
    return 0;
}