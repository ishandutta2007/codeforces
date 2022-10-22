#include<bits/stdc++.h>
#define rgi register int
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=200010,inf=998244353;
int n,m,fa[N],u,v,k[N],s[N],siz[N],sum,ans=inf;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int f[N],t[N],cnt;
int check(int x){
	while(x){
		if(x%10!=4&&x%10!=7)return 0;
		x/=10;
	}
	return 1;
}
signed main(){
	read(n,m);
	for(rgi i=1;i<=n;++i)f[i]=inf,fa[i]=i;
	for(rgi i=1;i<=m;++i)read(u,v),fa[find(u)]=find(v);
	for(rgi i=1;i<=n;++i)++k[find(i)];
	for(rgi i=1;i<=n;++i)++s[k[i]];
	for(rgi i=1;i<=n;++i){
		if(s[i])for(rgi j=1;j<=s[i];j<<=1){
            siz[++cnt]=j;
            t[cnt]=i*j;
        }
	}
	for(rgi i=1;i<=cnt;sum+=t[i++]){
		for(rgi j=sum;~j;--j)f[j+t[i]]=min(f[j+t[i]],f[j]+siz[i]);
	}
	for(rgi i=4;i<=n;++i)if(check(i))ans=min(ans,f[i]);
	write(ans==inf?-1:ans-1);
	return 0;
}