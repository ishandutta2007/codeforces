#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define mid (l+r>>1)
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
const int N=100010;
ll n;
ll L1[N],L2[N],R1[N],R2[N],x[N],y[N],p[N];
int check(ll g){
	int j=0;
	for(rgi i=0;i<n;++i){
		while(j<n&&(x[p[j]]-x[p[i]])<=g)++j;
		if(max(R2[j],L2[i])-min(R1[j],L1[i])<=g)return 1;
	}
	return 0;
}
signed main(){
	read(n);
	L1[0]=R1[n]=1ll<<40,L2[0]=R2[n]=-1ll<<40;
	for(int i=0;i<n;++i)read(x[i],y[i]),x[i]+=y[i],y[i]=x[i]-2*y[i],p[i]=i;
	sort(p,p+n,[&](int a,int b){return x[a]<x[b];});
	for(rgi i=0;i<n;++i)L1[i+1]=min(L1[i],y[p[i]]),L2[i+1]=max(L2[i],y[p[i]]);
	for(rgi i=n;i;--i)R1[i-1]=min(R1[i],y[p[i-1]]),R2[i-1]=max(R2[i],y[p[i-1]]);
	ll l=0,r=1ll<<40;
	while(l<r){
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%.9lf\n",1.0*l/2); 
	return 0;
}