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
const int N=1e5+5;
int n,x,y,a[N];
inline bool check(int p){
	for(ri i=p+1,up=min(p+y,n);i<=up;++i)if(a[p]>a[i])return 0;
	for(ri i=p-1,up=max(p-x,1);i>=up;--i)if(a[p]>a[i])return 0;
	return 1;
}
int main(){
	n=read(),x=read(),y=read();
	for(ri i=1;i<=n;++i)a[i]=read();
	for(ri i=1;i<=n;++i){
		if(check(i))return cout<<i,0;
	}
	return 0;
}