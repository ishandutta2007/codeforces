#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rsz resize
#define pb push_back
using namespace std;
#define gc getchar
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int mod=998244353;
typedef long long ll;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=2e5+5;
bool vis[N];
int n,las[N],ans[N],seq[N];
char s[N],str[N];
inline bool check(char x){
	char t='0';
	int ps=0;
	for(ri i=1;i<=n;++i){
		if(s[i]<t&&s[i]<x)return 0;
		if(s[i]<x)t=s[i],ans[i]=1,ps=i;
	}
	t='9';
	for(ri i=n;i;--i){
		if(s[i]>t&&s[i]>x)return 0;
		if(s[i]>x)t=s[i],ans[i]=2;
	}
	int ct=0;
	for(ri i=1;i<=n;++i)vis[i]=0;
	for(ri i=1;i<=n;++i)if(s[i]<x||(s[i]==x&&i>=ps))vis[i]=1,str[++ct]=s[i],ans[i]=1;
	for(ri i=1;i<=n;++i)if(!vis[i])str[++ct]=s[i],ans[i]=2;
	for(ri i=1;i<n;++i)if(str[i]>str[i+1])return 0;
	return 1;
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	for(ri tt=read();tt;--tt){
		n=read();
		scanf("%s",s+1);
		bool ff=0;
		for(ri i=1;i<n;++i)if(s[i]>s[i+1]){ff=1;break;}
		if(!ff){for(ri i=1;i<=n;++i)cout<<2;puts("");}
		else{
			bool fff=0;
			for(int i=0;i<9;++i){
				if(!check(i+'0'))continue;
				for(ri j=1;j<=n;++j)cout<<ans[j];
				puts("");
				fff=1;
				break;
			}
			if(!fff)puts("-");
		}
	}
	return 0;
}