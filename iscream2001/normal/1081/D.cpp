#pragma GCC optimize("-O2")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<bitset>
#include<ctime>
#include<cstdlib> 
#define LL long long
#define DB long double
#define pa pair<LL,int>
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void Out(LL x){
    if(x>9) Out(x/10);
    putchar(x%10+'0'); 
}
LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;	
    } 
    return re;
}

const LL P=998244353;
const int N=100050;
int n,m,k;
struct node{
	int l,r,v;
}d[N];
bool cmp(node A,node B){
	return A.v<B.v;
}
int fa[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int siz[N];
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    int kk=k;
    for(int i=1;i<=n;++i) fa[i]=i;
    int x;
    for(int i=1;i<=k;++i) x=read(),siz[x]=1;
    for(int i=1;i<=m;++i){
    	d[i].l=read();
    	d[i].r=read(); 
    	d[i].v=read();
	}
	sort(d+1,d+1+m,cmp);
	int u,v;
	for(int i=1;i<=m;++i){
		u=find(d[i].l);
		v=find(d[i].r);
		if(u==v) continue;
		if(siz[u]&&siz[v]) --k;
		if(siz[u]<siz[v]) swap(u,v);
		fa[v]=u;
		if(k==1){
			for(int j=1;j<=kk;++j) printf("%d ",d[i].v);
			return 0;
		}
	}
} 
/*
4 1
1 3 5 7

*/