#include<bits/stdc++.h>
#define rgi register int
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
const int N=200010,SZ=6300010;
ll n,a[N];
ll sum[SZ],ch[SZ][2],cnt,rt;
ll r[SZ],l[SZ];
ll ans;
#define g(x) (x>>d&1ll)
void ins(ll i,ll& k,ll d){
	++sum[k?k:k=++cnt],r[k]=i;
	if(!l[k])l[k]=i;
	if(~d)ins(i,ch[k][g(a[i])],d-1);
}
ll qry(ll k,ll d,ll x){
	if(l[k]==r[k])return x^a[l[k]];
	ll w=g(x);
	return qry(ch[k][w]?ch[k][w]:ch[k][w^1],d-1,x);
}
void dfs(ll x,ll d){
	if(!x||!~d)return;
	ll de=sum[ch[x][0]]>sum[ch[x][1]]?ch[x][0]:ch[x][1];
	ll fr=ch[x][0]^ch[x][1]^de;
	if(ch[x][0]&&ch[x][1]){
		ll res=(1ll<<31);
		for(rgi i=l[fr];i<=r[fr];++i){
			res=min(res,qry(de,d-1,a[i]));
		}
		ans+=res;
	}
	if(ch[x][0])dfs(ch[x][0],d-1);
	if(ch[x][1])dfs(ch[x][1],d-1);
}
signed main(){
	read(n);
	for(rgi i=1;i<=n;++i)read(a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(rgi i=1;i<=n;++i)ins(i,rt,31);
	dfs(rt,31);
	write(ans);
	return 0;
}