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
const int N=1000010;
int n,m;
int a[N],b[N],d[N],f[N],to[N],ban[N];
int main(){
	srand(233),read(n,m);
	for(rgi i=1;i<=m;++i)read(a[i],b[i]),++d[a[i]],++d[b[i]],to[i]=i;
	for(rgi i=1;i<=n;++i)f[i]=(d[i]+1>>1);
	random_shuffle(to+1,to+m+1);
	int cnt=0;
	for(rgi i=1;i<=m;++i){
		if(d[a[to[i]]]>f[a[to[i]]]&&d[b[to[i]]]>f[b[to[i]]])ban[i]=1,--d[a[to[i]]],--d[b[to[i]]],++cnt;
	}
	write(m-cnt,'\n');
	for(rgi i=1;i<=m;++i)if(!ban[i])write(a[to[i]],' ',b[to[i]],'\n');
	return 0;
}