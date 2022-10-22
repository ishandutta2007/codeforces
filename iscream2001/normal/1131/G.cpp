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
const LL P=1e9+7;
const int N=3e5+50;
const int M=1e7+10;
int n,m,Q;
int k[N];
vector<int> a[N],c[N];
int tp=0,cnt;
int l[M],r[M],q[M],h[M];
LL v[M],f[M],t[M];
void add(int x,LL y){
	x=10000002-x-1;
	while(x<10000002){
		t[x]=min(t[x],y);
		x+=x&-x;
	}
}
LL get(int x){
	x=10000002-x-1;
	LL re=inf;
	while(x){
		re=min(re,t[x]);
		x-=x&-x;
	}
	return re;
}
int main(){
    scanf("%d%d",&n,&m);
    int u;
    LL A,C;
    for(int i=1;i<=n;++i){
    	k[i]=read();
    	for(int j=1;j<=k[i];++j){
    		u=read();
    		a[i].push_back(u);
		}
		for(int j=1;j<=k[i];++j){
    		u=read();
    		c[i].push_back(u);
		}
	}
	scanf("%d",&Q);
	while(Q--){
		u=read();C=read();
		for(int i=0;i<a[u].size();++i){
			++tp;
			h[tp]=a[u][i];
			v[tp]=(LL)c[u][i]*C;
		}
	}
	l[1]=1;cnt=1;q[1]=1;
	for(int i=2;i<=m;++i){
		u=max(1,i-h[i]+1);
		while(cnt&&q[cnt]>=u){
			u=min(u,l[q[cnt]]);
			--cnt;
		}
		l[i]=u;
		q[++cnt]=i;
	}
	r[m]=m;cnt=1;q[1]=m;
	for(int i=m-1;i>=1;--i){
		u=min(m,i+h[i]-1);
		while(cnt&&q[cnt]<=u){
			u=max(u,r[q[cnt]]);
			--cnt;
		}
		r[i]=u;
		q[++cnt]=i;
	}
	for(int i=0;i<=10000002;++i) t[i]=inf;
	for(int i=1;i<=m;++i){
		f[i]=min(f[l[i]-1]+v[i],get(i));
		add(r[i],f[i-1]+v[i]);
	}
	printf("%lld\n",f[m]);
	return 0;
}
/*
5
1 2 2
1 2 2
*/