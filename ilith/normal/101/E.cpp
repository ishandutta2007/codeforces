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
const int N=20010,lim=10000;
ll n,m,p;
ll f[N],x[N],y[N];
bitset<N>b[lim+10];
vector<char>ans;
#define v(a,b) (x[a]+y[b])%p
signed main(){
	read(n,m,p);
	for(rgi i=1;i<=n;++i)read(x[i]);
	for(rgi i=1;i<=m;++i)read(y[i]);
	for(rgi i=1;i<=n;++i){
		for(rgi j=1;j<=m;++j){
			if(i!=1&&(f[j]>f[j-1]||j==1)){
				f[j]=f[j]+v(i,j);
				if(i>=lim)b[i-lim][j]=1;
			}
			else f[j]=f[j-1]+v(i,j);
		}
	}
	int ax=n,ay=m;
	while(ax>lim){
		if(b[ax-lim][ay])--ax,ans.push_back('C');
		else --ay,ans.push_back('S');
	}
	write(f[m],'\n');
	memset(f,0,sizeof f);
	for(rgi i=1;i<=ax;++i){
		b[i].reset();
		for(rgi j=1;j<=ay;++j){
			if(i!=1&&(f[j]>f[j-1]||j==1))f[j]=f[j]+v(i,j),b[i][j]=1;
			else f[j]=f[j-1]+v(i,j);
		}
	}
	while(ax!=1||ay!=1){
		if(b[ax][ay])--ax,ans.push_back('C');
		else --ay,ans.push_back('S');
	}
	reverse(ans.begin(),ans.end());
	for(char ch:ans)putchar(ch);
	return 0;
}