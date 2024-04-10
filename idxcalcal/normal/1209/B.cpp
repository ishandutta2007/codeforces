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
const int N=4e6+5;
int n,a[N],cg[N],b[N];
int vis[N];
char s[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	scanf("%s",s+1);
	for(ri i=1;i<=n;++i)a[i]=read(),b[i]=read();
	for(ri tg,i=1;i<=n;++i){
    	tg=s[i]-'0';
    	for(ri j=0;j<=100000;++j){
      		if(j>=b[i]&&((j-b[i])%a[i])==0){
        	    tg^=1;
	      	}
    		vis[j] += tg;
    	}
  	}
  	int res=0;
  	for(ri i=0;i<=100000;++i)res=max(res,vis[i]);
  	cout<<res;
	return 0;
}