#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<tr1/unordered_map>
#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define pb push_back
#define rsz resize
#define sz(x) (int)(x).size()
#define lb lower_bound
#define rb upper_bound
#define all(x) (x).begin() (x).end()
using namespace std;
using namespace __gnu_pbds;
const int rlen=1<<18|1;
#define gc getchar
inline int read(){
	int ans=0;
	char ch=gc();
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
inline vector<char>Read(){
	char ch=gc();
	vector<char>res;
	res.push_back('0');
	while(!(ch=='#'||ch=='.'))ch=gc();
	while((ch=='#'||ch=='.'))res.pb(ch),ch=gc();
	return res;
}
typedef long long ll;
inline ll readl(){
	ll ans=0;
	char ch=gc();
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;	
}
inline char gch(){
	char ch=gc();
	while(!isalpha(ch))ch=gc();
	return ch;
}
typedef pair<int,int> pii;
const int mod=998244353;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (int)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int fix(const int&x){return (x%mod+mod)%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
inline int sgn(int x){return (x>0)-(x<0);}
const double pi=acos(-1.0),eps=1e-16;
inline double sgn(double x){return (x>eps)-(x<-eps);}
const int N=1e6+5;
int n,m;
vector<char>s[N];
vector<bool>ok[N];
vector<int> f1[3][N],f2[3][N];
inline void check1(){
	for(ri i=2;i<m;++i)if(s[1][i]=='#')puts("0"),exit(0);
	puts("1");
	exit(0);
}
inline void check2(){
	for(ri i=2;i<n;++i)if(s[i][1]=='#')puts("0"),exit(0);
	puts("1");
	exit(0);
}
inline bool trans(){
	ok[1][1]=1;
	for(ri i=1;i<=n;++i)for(ri j=1;j<=m;++j){
		if(i+j==2)continue;
		ok[i][j]=0;
		if(s[i][j]=='#')continue;
		if(ok[i][j-1]||ok[i-1][j])ok[i][j]=1;
	}
	return ok[n][m];
}
int md[3]={200301121,123123424,581274847};
inline int add(int a,int b,int mod){return (a+=b)<mod?a:a-mod;}
inline int mul(int a,int b,int mod){return (ll)a*b%mod;}
inline void DP1(){
	for(ri k=0;k<3;++k){
		f1[k][1][1]=1;
		for(ri i=1;i<=n;++i)for(ri j=1;j<=m;++j){
			if(i+j==2)continue;
			if(s[i][j]=='#')continue;
			f1[k][i][j]=add(f1[k][i-1][j],f1[k][i][j-1],md[k]);
		}
	}
}
inline void DP2(){
	for(ri k=0;k<3;++k){
		f2[k][n][m]=1;
		for(ri i=n;i;--i)for(ri j=m;j;--j){
			if(i+j==n+m)continue;
			if(s[i][j]=='#')continue;
			f2[k][i][j]=add(f2[k][i+1][j],f2[k][i][j+1],md[k]);
		}
	}
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read();
	for(ri i=0;i<=n+1;++i){
		ok[i].resize(m+2);
		for(ri j=0;j<3;++j)f1[j][i].resize(m+2),f2[j][i].resize(m+2);
	}
	for(ri i=1;i<=n;++i)s[i]=Read(),ok[i].resize(m+1);
	if(n==1)check1();
	if(m==1)check2();
	if(!trans())return puts("0"),0;
	if(s[1][2]=='#'||s[2][1]=='#'||s[n-1][m]=='#'||s[n][m-1]=='#'){
		cout<<1;
		return 0;
	}
	DP1();
	DP2();
	for(ri i=1;i<=n;++i)for(ri j=1;j<=m;++j){
		if(i==1&&j==1)continue;
		if(i==n&&j==m)continue;
		bool ff=1;
		for(ri k=0;k<3;++k){
			if(mul(f1[k][i][j],f2[k][i][j],md[k])!=f1[k][n][m]){
				ff=0;
				break;
			}
		}
		if(ff){
			puts("1");
			return 0;
		}
	}
	cout<<2;
	return 0;
}