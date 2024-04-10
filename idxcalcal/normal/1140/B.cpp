#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int mod=1e9+7;
typedef long long ll;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;} 
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=10005;
char s[N];
int n;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	for(ri tt=read();tt;--tt){
		n=read(),scanf("%s",s+1);
		int pre=0,suf=0;
		for(ri i=1;i<=n;++i){
			if(s[i]=='<')++pre;
			else break;
		}
		for(ri i=n;i;--i){
			if(s[i]=='>')++suf;
			else break;
		}
		cout<<min(pre,suf)<<'\n';
	}
	return 0;
}