#include<bits/stdc++.h>
#define rgi register int
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
typedef unsigned long long ull;
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
const ull Base=1145;
char s1[N],s2[N];
ull Hash1[N],Hash2[N],r[N],p[N];
int n,maxn,p1,p2;
vector<int>v[N];
int main(){
	gets(s1+1),gets(s2+1),n=strlen(s1+1),reverse(s2+1,s2+n+1),p[0]=1;
	if(strlen(s2+1)!=n)return puts("-1 -1"),0;
	for(rgi i=1;i<=n;++i)
		p[i]=p[i-1]*Base,Hash1[i]=Hash1[i-1]*Base+s1[i],Hash2[i]=Hash2[i-1]*Base+s2[i];
	for(rgi i=n;i;--i) r[i]=r[i+1]*Base+s2[i];
	for(rgi i=1;i<=n;++i){
		if(s2[i]==s1[n]){
			int l=1,r=i;
			while(l<r){
				int midd=l+r+1>>1;
				if(Hash2[i]-Hash2[i-midd]*p[midd]==Hash1[n]-Hash1[n-midd]*p[midd]) l=midd;else r=midd-1;
			}
			v[i-l].push_back(i);
		}
	}
	for(auto x:v[0]) x>maxn?maxn=x:0;
	for(rgi i=1;i<=n;++i){
		if(s1[i]==s2[i]){
			for(auto x:v[i]) x>maxn?maxn=x:0;
			if(maxn>i&&r[maxn+1]==Hash1[i+n-maxn]-Hash1[i]*p[n-maxn]) p1=i,p2=i+n-maxn+1;
		}
		else break;
	}
	cout<<p1-1<<' '<<p2-1<<'\n';
	return 0;
}