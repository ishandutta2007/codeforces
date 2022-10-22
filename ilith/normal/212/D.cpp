#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define fi first
#define se second
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
const int N=1000010;
ll n,m,l[N],r[N],a[N],q[N],c,ans[N];
signed main(){
	read(n);
	for(rgi i=1;i<=n;++i){
		read(a[i]);
		while(c&&a[q[c]]>a[i])r[q[c--]]=i-1;
		q[++c]=i;
	}
	c=0;
	for(rgi i=n;i;--i){
		while(c&&a[q[c]]>=a[i])l[q[c--]]=i+1;
		q[++c]=i;
	}
	for(rgi i=1;i<=n;++i){
		if(!l[i])l[i]=1;
		if(!r[i])r[i]=n;
	}
	for(rgi i=1;i<=n;++i){
		int mn=min(i-l[i]+1,r[i]-i+1),mx=max(i-l[i]+1,r[i]-i+1);
		ans[1]+=a[i],ans[mn+1]-=a[i],ans[mx+1]-=a[i],ans[r[i]-l[i]+3]+=a[i];
	}
	for(rgi i=1;i<=n;++i)ans[i]+=ans[i-1];
	for(rgi i=1;i<=n;++i)ans[i]+=ans[i-1];
	read(m);
	while(m--){
		int k;
		read(k);
		printf("%.10lf\n",ans[k]*1.00/(n-k+1));
	}
	return 0;
}