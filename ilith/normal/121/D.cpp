#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int ll
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
const int N=600010,inf=1e18,maxn=30;
ll n,k,p[N],cnt,len=inf,l[N],r[N],ans,j;
double suml,sumr;
void dfs(int x){
	if(x>inf)return;
	p[++cnt]=x,dfs(x*10+4),dfs(x*10+7);
}
struct cmpl{
    bool operator()(int x,int y){return l[x]==l[y]?x<y:l[x]<l[y];}
};
struct cmpr{
    bool operator()(int x,int y){return r[x]==r[y]?x<y:r[x]<r[y];}
};
multiset<int,cmpr>s1;
multiset<int,cmpl>s2;
bool calc(ll L,ll R){
	double sz2=s2.size(),sz1=n-sz2-s1.size();
	return (sumr-sz2*L+sz1*R-suml)<=k;
}
signed main(){
	read(n,k),dfs(4),dfs(7),sort(p+1,p+cnt+1);
	for(rgi i=1;i<=n;++i)read(l[i],r[i]),len=min(len,r[i]-l[i]),s2.insert(i);
	s1.clear(),s2.clear();
	for(rgi i=1;i<=n;++i)s2.insert(i),sumr+=l[i];
	for(rgi i=1;i<=cnt;++i){
		while(p[j+1]-p[i]<=len&&j<cnt){
			++j;
			while(s2.size()){
				ll k=*s2.begin();
				if(l[k]>p[j])break;
				s2.erase(k),sumr-=l[k],s1.insert(k);
			}
			while(s1.size()){
				ll k=*s1.begin();
				if(r[k]>=p[j])break;
				s1.erase(k),suml+=r[k];
			}
			if(calc(p[i],p[j]))ans=max(ans,j-i+1);
			else break;
		}
	}
	write(ans);
	return 0;
}