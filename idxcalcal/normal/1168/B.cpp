#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
	#undef gc
}
typedef pair<int,int> pii;
typedef long long ll;
const int mod=998244353;
typedef vector<int> poly;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:a-=mod;}
inline void Dec(int&a,int b){(a-=b)<0?a+=mod:a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=3e5+5;
char s[N];
int n;
inline bool check(int l,int r){
	for(ri len=1;len*2<=r-l+1;++len)for(ri i=l;i+len*2<=r;++i)if(s[i]==s[i+len]&&s[i+len]==s[i+len*2])return 1;
	return 0;
}
inline ll solve(int L,int R){
	ll ret=0;
	if(L>R)return 0;
	if(R-L+1<=10){
		for(ri i=L;i<=R;++i)for(ri j=L+1;j<=R;++j)if(check(i,j))++ret;
		return ret;
	}
	for(ri i=L;i<=R;++i){
		if(check(L,i)){
			int j=L;
			for(;j<=i;++j)if(!check(j,i))break;
			return solve(j,R)+(ll)(R-i+1)*(j-L);
		}
	}
	return 0;
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	scanf("%s",s+1),n=strlen(s+1);
	cout<<solve(1,n);
	return 0;
}