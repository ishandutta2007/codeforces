//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1e5+5,maxw=2e5+5,maxb=455,mod=1e9+7;
int n,q;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool bj[maxb];
int len,p[maxb];
void pre(int lim){
	for(int i=2;i<=lim;i++){
		if(!bj[i])p[++len]=i;
		for(int j=1;i*p[j]<=lim&&j<=len;j++){
			bj[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	return ;
}
int mp[maxw];
struct seg1{
	int a[maxn];
	int mx[4*maxn];
	void build(int k,int l,int r){
		if(l==r){mx[k]=a[l];return ;}
		int mid=l+((r-l)>>1);
		build(k<<1,l,mid);build(k<<1|1,mid+1,r);
		mx[k]=max(mx[k<<1],mx[k<<1|1]);
		return ;
	}
	int query(int k,int l,int r,int x,int y){
		if(mx[k]==1)return 1;
		if(l>=x&&r<=y)return mx[k];
		int mid=l+((r-l)>>1);
		int res=1;
		if(x<=mid)res=query(k<<1,l,mid,x,y);
		if(y>mid)res=max(res,query(k<<1|1,mid+1,r,x,y));
		return res;
	}
}S[90];
struct seg2{
	struct node{int ls,rs,p;}t[17*17*maxn];
	int tot,rt[4*maxn];
	void modify2(int &k,int l,int r,int x,int v){
		if(!k)k=++tot,t[k].p=1;
		t[k].p=1ll*t[k].p*v%mod;
		if(l==r)return ;
		int mid=l+((r-l)>>1);
		if(x<=mid)modify2(t[k].ls,l,mid,x,v);
		else modify2(t[k].rs,mid+1,r,x,v);
		return ;
	}
	void modify1(int k,int l,int r,int x,int y,int v){
		modify2(rt[k],0,n,y,v);
		if(l==r)return ;
		int mid=l+((r-l)>>1);
		if(x<=mid)modify1(k<<1,l,mid,x,y,v);
		else modify1(k<<1|1,mid+1,r,x,y,v);
		return ;
	}
	int query2(int k,int l,int r,int x,int y){
		if(!k)return 1;
		if(l>=x&&r<=y)return t[k].p;
		int mid=l+((r-l)>>1);
		int lt=1,rt=1;
		if(x<=mid)lt=query2(t[k].ls,l,mid,x,y);
		if(y>mid)rt=query2(t[k].rs,mid+1,r,x,y);
		return 1ll*lt*rt%mod;
	}
	int query1(int k,int l,int r,int x,int y){
		if(l>=x&&r<=y)return query2(rt[k],0,n,0,x-1);
		int mid=l+((r-l)>>1);
		int lt=1,rt=1;
		if(x<=mid)lt=query1(k<<1,l,mid,x,y);
		if(y>mid)rt=query1(k<<1|1,mid+1,r,x,y);
		return 1ll*lt*rt%mod;
	}
}T;
int main(){
    pre(sqrt(200000));
	n=read();
	for(int i=1;i<=n;i++){
		int x;
		x=read();
		for(int j=1;j<=len;j++){
			int pw=1;
			while(x%p[j]==0)x/=p[j],pw*=p[j];
			S[j].a[i]=pw;
		}
		if(x>1)T.modify1(1,1,n,i,mp[x],x),mp[x]=i;
	}
	for(int i=1;i<=len;i++)S[i].build(1,1,n);
	q=read();
	int lstans=0;
	while(q--){
		int l,r,res=1;
		l=read();r=read();
		l=(l+lstans)%n+1;
		r=(r+lstans)%n+1;
		if(l>r)swap(l,r);
		for(int j=1;j<=len;j++)res=1ll*res*S[j].query(1,1,n,l,r)%mod;
		res=1ll*res*T.query1(1,1,n,l,r)%mod;
		printf("%d\n",lstans=res);
	}
    return 0;
}