#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,W=1e9;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct seg{int ls,rs,mn,mx,laz;}t[60*maxn];
int rt,tot=0;
int newseg(int l,int r){
	int k=++tot;
	t[k]=(seg){0,0,l,r,0};
	return k;
}
void add_laz(int x,int v){t[x].mn+=v,t[x].mx+=v,t[x].laz+=v;}
void pushup(int x){t[x].mx=max(t[t[x].ls].mx,t[t[x].rs].mx);t[x].mn=min(t[t[x].ls].mn,t[t[x].rs].mn);}
void pushdown(int k){
	if(t[k].laz==0)return ;
	add_laz(t[k].ls,t[k].laz),add_laz(t[k].rs,t[k].laz);
	t[k].laz=0;
	return ;
}
void modify(int x,int l,int r,int v){
	if(t[x].mx<v){add_laz(x,1);return ;}
	if(t[x].mn>v){add_laz(x,-1);return ;}
	if(t[x].mn==t[x].mx)return ;
	int mid=l+((r-l)>>1);
	if(!t[x].ls)t[x].ls=newseg(l,mid);
	if(!t[x].rs)t[x].rs=newseg(mid+1,r);
	pushdown(x);
	modify(t[x].ls,l,mid,v);modify(t[x].rs,mid+1,r,v);
	pushup(x);
	return ;
}
int query(int x,int l,int r,int v){
	if(l==r)return t[x].mx;
	int mid=l+((r-l)>>1);
	if(!t[x].ls)t[x].ls=newseg(l,mid);
	if(!t[x].rs)t[x].rs=newseg(mid+1,r);
	pushdown(x);
	if(v<=mid)return query(t[x].ls,l,mid,v);
	return query(t[x].rs,mid+1,r,v);
}
int main(){
//	freopen("CF1614E.in","r",stdin);
//    freopen("CF1614E.out","w",stdout);
    int n,lstans=0;
	n=read();
	rt=newseg(0,W);
	for(int i=1;i<=n;i++){
		int t,k;
		t=read();
		modify(rt,0,W,t);
		k=read();
		for(int j=1;j<=k;j++){
			int x;
			x=(read()+lstans)%(W+1);
			printf("%d\n",lstans=query(rt,0,W,x));
		}
	}
    return 0;
}