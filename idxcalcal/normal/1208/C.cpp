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
const int N=2005;
int n,ans[N][N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri l=0,r=15,a,b,i=0;i<n;i+=4)for(ri j=0;j<n;j+=4){
		a=i,b=j;
		ans[a][b]=l;
		ans[a][b+1]=l+1;
		ans[a+1][b]=l+2;
		ans[a+1][b+1]=l+3;
		a=i,b=j+2;
		l+=4;
		ans[a][b]=l+2;
		ans[a][b+1]=l+3;
		ans[a+1][b]=l;
		ans[a+1][b+1]=l+1;
		a=i+2,b=j;
		l+=4;
		ans[a][b]=l+1;
		ans[a][b+1]=l;
		ans[a+1][b]=l+3;
		ans[a+1][b+1]=l+2;
		a=i+2,b=j+2;
		l+=4;
		ans[a][b]=l+3;
		ans[a][b+1]=l+2;
		ans[a+1][b]=l+1;
		ans[a+1][b+1]=l;
		l+=4;
	}
	for(ri i=0;i<n;++i,puts(""))for(ri j=0;j<n;++j)cout<<ans[i][j]<<' ';
	return 0;
}