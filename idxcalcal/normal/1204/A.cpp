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
char s[105];
int n;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	scanf("%s",s+1),n=strlen(s+1);
	bool f=1;
	for(ri i=2;i<=n;++i){
		if(s[i]=='1'){
			f=0;
			break;
		}
	}
	if(!f)++n;
	cout<<n/2;
	return 0;
}