#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
char buf[1<<20],*p1,*p2;
typedef long long ll;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
inline int read(){
    int x=0;bool f=0;
    char c=getchar();
    while(!isdigit(c)&&c!='-')c=getchar();
    if(c=='-')f=1,c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return f?-x:x;
}
const int N=1e6+5;
int n,p[N],c[N],ans;
ll a[N],k;
ll qgcd(ll a, ll b) {
    if(!a) return b;
    if(!b) return a;
    if(!(a & 1 || b & 1))
        return qgcd(a >> 1, b >> 1) << 1;
    if(!(a & 1)) return qgcd(a >> 1, b);
    if(!(b & 1)) return qgcd(a, b >> 1);
    return qgcd(std::abs(a - b), std::min(a, b));
}
signed main(){
	n=read();
	FOR(i,1,n)a[i]=read();
	FOR(i,2,n)p[i]=read();
	ROF(i,n,1)a[p[i]]+=a[i],p[i]=0;
	FOR(i,1,n)if((k=a[1]/qgcd(a[i],a[1]))<=n)++c[k];
	ROF(i,n,1)if(c[i])for(int j=i+i;j<=n;j+=i)c[j]+=c[i];
	FOR(i,1,n)if(c[i]==i){
		ans+=++p[i];
		for(int j=i+i;j<=n;j+=i)p[j]+=p[i];
	}
	printf("%d",(ans+1)/2);
	return 0;
}