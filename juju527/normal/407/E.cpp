#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int tp1,st1[maxn];
int tp2,st2[maxn];
map<int,int> pre;
int v[maxn<<2],laz[maxn<<2];
void pushup(int k){v[k]=min(v[k<<1],v[k<<1|1]);return ;}
void add_laz(int k,int w){v[k]+=w;laz[k]+=w;return ;}
void pushdown(int k){
	if(!laz[k])return ;
	add_laz(k<<1,laz[k]);add_laz(k<<1|1,laz[k]);
	laz[k]=0;
	return ;
}
void modify(int k,int l,int r,int x,int y,int w){
	if(l>y||r<x)return ;
	if(l>=x&&r<=y){add_laz(k,w);return ;}
	int mid=l+((r-l)>>1);
	pushdown(k);
	modify(k<<1,l,mid,x,y,w),modify(k<<1|1,mid+1,r,x,y,w);
	pushup(k);
	return ;
}
vector<pair<int,pair<int,int>>> p;
void find(int k,int l,int r,int x,int y){
	if(l>y||r<x)return ;
	if(l>=x&&r<=y){p.push_back(make_pair(k,make_pair(l,r)));return ;}
	int mid=l+((r-l)>>1);
	pushdown(k);
	find(k<<1,l,mid,x,y),find(k<<1|1,mid+1,r,x,y);
	return ;
}
int main(){
    int n,K,d;
	n=read();K=read();d=read();
	if(!d){
		int lst=1,L=0,R=0,res=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i-1]!=a[i]){
				if(i-lst>res)res=i-lst,L=lst,R=i-1;
				lst=i;
			}
		}
		if(n-lst+1>res)res=n-lst+1,L=lst,R=n;
		printf("%d %d\n",L,R);
		return 0;
	}
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=(a[i]-(a[i]%d+d)%d)/d;
	int lst=0,res=0,L=0,R=0,Lim=0;
	for(int i=1;i<=n;i++){
		if((a[i]%d+d)%d!=(a[lst]%d+d)%d)lst=i;
		Lim=max(Lim,pre[a[i]]+1);
		int lim=max(Lim,lst);
		pre[a[i]]=i;
		int pos=i;
		modify(1,1,n,i,i,i);
		while(tp1&&b[st1[tp1]]<=b[i])modify(1,1,n,st1[tp1-1]+1,st1[tp1],b[i]-b[st1[tp1]]),tp1--;
		while(tp2&&b[st2[tp2]]>=b[i])modify(1,1,n,st2[tp2-1]+1,st2[tp2],b[st2[tp2]]-b[i]),tp2--;
		st1[++tp1]=i;st2[++tp2]=i;
		p.clear();find(1,1,n,lim,i);
		for(int j=0;j<p.size();j++){
			int k=p[j].fi,l=p[j].se.fi,r=p[j].se.se;
			if(v[k]>K+i)continue;
			while(1){
				if(l==r){
					if(i-l+1>res)res=i-l+1,L=l,R=i;
					break;
				}
				int mid=l+((r-l)>>1);
				pushdown(k);
				if(v[k<<1]<=K+i)k=k<<1,r=mid;
				else k=k<<1|1,l=mid+1;
			}
			break;
		}
	}
	printf("%d %d\n",L,R);
    return 0;
}