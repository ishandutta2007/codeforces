#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<vector>
#include<bitset>
#define N 100001
#define M 1<<18
#define LL long long
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
using namespace std;
const int mod=1000000007;
int n,ans,a[N],pre[N],nxt[N];
map<int,int> last;
int l[M],r[M],tagl[M],tagr[M];
int siz[M],sum[M];
struct node{
	int l,r,sum,sum2;
	node operator + (const node &i)const{
		return (node){(l+i.l)%mod,(r+i.r)%mod,(sum+i.sum)%mod,(sum2+i.sum2)%mod};
	}
}e[M];
void dool(int k,int x){
	tagl[k]=x;
	e[k].l=1ll*siz[k]*x%mod;
	e[k].sum=1ll*e[k].r*x%mod;
}
void door(int k,int x){
	tagr[k]=x;
	e[k].r=1ll*siz[k]*x%mod;
	e[k].sum=1ll*e[k].l*x%mod;
	e[k].sum2=1ll*sum[k]*x%mod;
}
void push(int k){
	if(tagl[k]){
		dool(k<<1,tagl[k]);
		dool(k<<1|1,tagl[k]);
		tagl[k]=0;
	}
	if(tagr[k]){
		door(k<<1,tagr[k]);
		door(k<<1|1,tagr[k]);
		tagr[k]=0;
	}
}
void upd(int k){
	e[k]=e[k<<1]+e[k<<1|1];
}
void build(int k,int a,int b){
	l[k]=a;r[k]=b;siz[k]=b-a+1;
	if(a==b){
		sum[k]=a;
		return;
	}
	build(k<<1,a,a+b>>1);
	build(k<<1|1,(a+b>>1)+1,b);
	sum[k]=(sum[k<<1]+sum[k<<1|1])%mod;
}
void modl(int k,int a,int b,int c){
	if(a<=l[k] && b>=r[k]){
		dool(k,c+1);
		return;
	}
	push(k);
	int m=l[k]+r[k]>>1;
	if(b<=m)modl(k<<1,a,b,c);
	else if(a>m)modl(k<<1|1,a,b,c);
	else modl(k<<1,a,b,c),modl(k<<1|1,a,b,c);
	upd(k);
}
void modr(int k,int a,int b,int c){
	if(a<=l[k] && b>=r[k]){
		door(k,c);
		return;
	}
	push(k);
	int m=l[k]+r[k]>>1;
	if(b<=m)modr(k<<1,a,b,c);
	else if(a>m)modr(k<<1|1,a,b,c);
	else modr(k<<1,a,b,c),modr(k<<1|1,a,b,c);
	upd(k);
}
node query(int k,int a,int b){
	if(a<=l[k] && b>=r[k])return e[k];
	push(k);
	int m=l[k]+r[k]>>1;
	if(b<=m)return query(k<<1,a,b);
	else if(a>m)return query(k<<1|1,a,b);
	else return query(k<<1,a,b)+query(k<<1|1,a,b);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i){
		pre[i]=last[a[i]];
		last[a[i]]=i;
	}
	last.clear();
	for(int i=n;i;--i){
		nxt[i]=last[a[i]]?last[a[i]]:n+1;
		last[a[i]]=i;
	}
	last.clear();
	build(1,1,n);
	static int stl[N],str[N];
	int tl=0,tr=0,lb=1;
	for(int i=1;i<=n;++i){
		if(last[a[i]]>=lb)lb=last[a[i]]+1;
		last[a[i]]=i;
		while(tl && pre[stl[tl]]<pre[i])--tl;
		modl(1,stl[tl]+1,i,pre[i]);
		stl[++tl]=i;
		while(tr && nxt[str[tr]]>nxt[i])--tr;
		modr(1,str[tr]+1,i,nxt[i]);
		str[++tr]=i;
		node now=query(1,lb,i);
		ans=((LL)ans+now.sum2-now.sum+now.l*(i+1ll)-(i+lb)*(i-lb+1ll)/2%mod*(i+1))%mod;
	}
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
}