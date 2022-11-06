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
}
const int mod=998244353;
typedef pair<int,int> pii;
typedef long long ll;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;} 
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=3e5+5;
int a[2][N],sig[2],f[N],g[N],n,k;
inline int calc(int l,int r,int len){
	if(l>r)swap(l,r);
	if(!(l+r))return mul(k,ksm(k-1,len-1));
	if(!l)return ksm(k-1,len);
	return l==r?g[len]:f[len];
}
inline int solve(int*a,int n){
	for(ri i=1;i<n;++i)if(~a[i]&&a[i]==a[i+1])return 0;
	int ret=1;
	for(ri pre=0,suf,l=1,r;l<=n;l=r+1){
		while(l<=n&&~a[l])pre=a[l++];
		if(l>n)break;
		r=l;
		while(a[r+1]==-1)++r;
		suf=a[r+1];
		Mul(ret,calc(pre,suf,r-l+1));
	}
	return ret;
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),k=read();
	f[0]=1,f[1]=k-2,g[0]=0,g[1]=k-1;
	for(ri i=2;i<=n;++i){
		f[i]=mul(k-2,ksm(k-1,i-1));
		Add(f[i],f[i-2]);
		g[i]=mul(k-2,ksm(k-1,i-1));
		Add(g[i],g[i-2]);
	}
	for(ri i=1;i<=n;++i)a[i&1][++sig[i&1]]=read();
	cout<<mul(solve(a[0],sig[0]),solve(a[1],sig[1]));
	return 0;
}