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
const int mod=998244853;
typedef pair<int,int> pii;
typedef long long ll;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;} 
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
typedef long long ll;
const int N=2e6+5;
char s[N],t[N];
int n,f[2][N],g[2][N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	scanf("%s",s+1),n=strlen(s+1);
	for(ri i=n;i;--i){
		f[0][i]=max(f[1][i+1],f[0][i+1])+(s[i]=='0');
		f[1][i]=f[1][i+1]+(s[i]=='1');
	}
	vector<char>s;
	for(ri i=n;i;--i){
		g[0][i]=max(g[1][i+1],g[0][i+1])+1;
		g[1][i]=g[1][i+1];
		if(max(f[0][i],f[1][i])==max(g[0][i],g[1][i]))s.push_back('0');
		else{
			g[0][i]=max(g[0][i+1],g[1][i+1]);
			g[1][i]=g[1][i+1]+1;
			s.push_back('1');
		}
	}
	reverse(s.begin(),s.end());
	for(ri i=0;i<s.size();++i)cout<<s[i];
	return 0;
}