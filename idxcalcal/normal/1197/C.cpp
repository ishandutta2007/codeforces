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
typedef pair<int,int> pii;
typedef long long ll;
const int mod=998244353;
inline int add(const int&a,const int&b){return a+b>=mod?a+b-mod:a+b;}
inline int dec(const int&a,const int&b){return a>=b?a-b:a-b+mod;}
inline int mul(const int&a,const int&b){return (ll)a*b%mod;}
inline void Add(int&a,const int&b){a=a+b>=mod?a+b-mod:a+b;}
inline void Dec(int&a,const int&b){a=a>=b?a-b:a-b+mod;}
inline void Mul(int&a,const int&b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,a=mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=3e5+5;
int n,k,a[N];
int main(){
	n=read(),k=read();
	for(ri i=1;i<=n;++i)a[i]=read();
	n=unique(a+1,a+n+1)-a-1;
	if(n<=k)return puts("0"),0;
	int ans=a[n]-a[1];
	for(ri i=2;i<=n;++i)a[i-1]=a[i]-a[i-1];
	sort(a+1,a+n);
	for(ri i=n-1,j=1;j<k;--i,++j)ans-=a[i];
	cout<<ans;
	return 0;
}