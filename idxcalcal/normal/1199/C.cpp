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
	#undef gc
}
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
inline int add(const int&a,const int&b){return a+b>=mod?a+b-mod:a+b;}
inline int dec(const int&a,const int&b){return a>=b?a-b:a-b+mod;}
inline int mul(const int&a,const int&b){return (ll)a*b%mod;}
inline void Add(int&a,const int&b){a=a+b>=mod?a+b-mod:a+b;}
inline void Dec(int&a,const int&b){a=a>=b?a-b:a-b+mod;}
inline void Mul(int&a,const int&b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,a=mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=4e5+5;
int n,I,a[N],b[N],m;
int main(){
	n=read(),I=read();
	for(ri i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	int cnt=0,lim=1<<(min(20,(I*8)/n));
	
	for(ri i=1;i<=n;++i){
		if(a[i]^a[i-1])a[++cnt]=a[i],b[cnt]=1;
		else ++b[cnt];
	}
	if(cnt<=lim)return cout<<0,0;
	int sum=0,ans=0;
	for(ri i=1;i<=lim;++i)sum+=b[i];
	ans=sum;
	for(ri i=lim+1;i<=cnt;++i){
		sum-=b[i-lim],sum+=b[i];
		ans=max(ans,sum);
	}
	cout<<n-ans;
	return 0;
}