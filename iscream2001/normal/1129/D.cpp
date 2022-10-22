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
#define LL long long
#define ui unsigned int
#define ull unsigned long long
using namespace std;
  
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
    if(x>9) Out(x/10);
    putchar('0'+x%10);
}
LL gcd(LL x,LL y){
    if(!y) return x;
    return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
const double eps=1e-6;
const LL inf=1e18;
const int P=998244353;
const int N=1e5+400;
int n,K,E=320;
int a[N],b[N],las[N],hed[N],g[N];
int S=0;
int h[320][N+N];
int f[N],tag[320];
void add(int &x,int y){x+=y;if(x>=P)x-=P;if(x<0)x+=P;}
void pls(int l,int r){
	if(l>r) return;
	int pl=g[l],pr=g[r];
	if(g[l]==g[r]){
		for(int i=l;i<=r;++i){
			add(h[pl][b[i]],P-f[i]);
			++b[i];
			add(h[pl][b[i]],f[i]);
			if(b[i]+tag[pl]==K+N+1) add(S,P-f[i]);
		}
		return;
	}
	for(int i=l;i<=pl*E;++i){
		add(h[pl][b[i]],P-f[i]);
		++b[i];
		add(h[pl][b[i]],f[i]);
		if(b[i]+tag[pl]==K+N+1) add(S,P-f[i]);
	}
	for(int i=pl+1;i<pr;++i){
		add(S,P-h[i][K+N-tag[i]]);
		++tag[i];
	}
	for(int i=(pr-1)*E+1;i<=r;++i){
		add(h[pr][b[i]],P-f[i]);
		++b[i];
		add(h[pr][b[i]],f[i]);
		if(b[i]+tag[pr]==K+N+1) add(S,P-f[i]);
	}
}
void del(int l,int r){
	if(l>r) return;
	int pl=g[l],pr=g[r];
	if(g[l]==g[r]){
		for(int i=l;i<=r;++i){
			add(h[pl][b[i]],P-f[i]);
			--b[i];
			add(h[pl][b[i]],f[i]);
			if(b[i]+tag[pl]==K+N) add(S,f[i]);
		}
		return;
	}
	for(int i=l;i<=pl*E;++i){
		add(h[pl][b[i]],P-f[i]);
		--b[i];
		add(h[pl][b[i]],f[i]);
		if(b[i]+tag[pl]==K+N) add(S,f[i]);
	}
	for(int i=pl+1;i<pr;++i){
		add(S,h[i][K+N+1-tag[i]]);
		--tag[i];
	}
	for(int i=(pr-1)*E+1;i<=r;++i){
		add(h[pr][b[i]],P-f[i]);
		--b[i];
		add(h[pr][b[i]],f[i]);
		if(b[i]+tag[pr]==K+N) add(S,f[i]);
	}
}
void push(int x){
	b[x]=N;add(h[g[x]][N],f[x]);add(S,f[x]);
}
int main(){
    scanf("%d%d",&n,&K);
    for(int i=1;i<=n;++i){
    	a[i]=read();
    	las[i]=hed[a[i]];
    	hed[a[i]]=i;
    	g[i]=(i-1)/E+1;
	}
	b[1]=N;f[1]=1;h[g[1]][N]=1;S=1;
	for(int i=1;i<=n;++i){
		pls(las[i]+1,i);
		del(las[las[i]]+1,las[i]);
		f[i+1]=S;
		//cout<<i<<" "<<f[i+1]<<endl;
		push(i+1);
	}
	printf("%d\n",f[n+1]);
	return 0;
}
/*
5
1 2 2
1 2 2
*/