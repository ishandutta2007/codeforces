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
const int N=55;
int n,m,f[N][N][N][N],a[N][N];
char s[N];
inline int dfs(int x1,int y1,int x2,int y2){
	if(~f[x1][y1][x2][y2])return f[x1][y1][x2][y2];
	if(x1>x2||y1>y2)return f[x1][y1][x2][y2]=0;
	if(x1==x2&&y1==y2)return f[x1][y1][x2][y2]=a[x1][y1];
	int ret=max(x2-x1+1,y2-y1+1);
	for(ri a=x1;a<x2;++a)ret=min(ret,dfs(x1,y1,a,y2)+dfs(a+1,y1,x2,y2));
	for(ri b=y1;b<y2;++b)ret=min(ret,dfs(x1,y1,x2,b)+dfs(x1,b+1,x2,y2));
	return f[x1][y1][x2][y2]=ret;
}
int main(){
	n=read();
	for(ri i=1;i<=n;++i){
		scanf("%s",s+1);
		for(ri j=1;j<=n;++j)a[i][j]=s[j]=='#';
	}
	memset(f,-1,sizeof(f));
	cout<<dfs(1,1,n,n);
	return 0;
}