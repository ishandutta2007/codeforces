#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef long long ll;
const int mod=998244353;
inline int add(const int&a,const int&b){return a+b>=mod?a+b-mod:a+b;}
inline int dec(const int&a,const int&b){return a>=b?a-b:a-b+mod;}
inline int mul(const int&a,const int&b){return (ll)a*b%mod;}
inline void Add(int&a,const int&b){a=a+b>=mod?a+b-mod:a+b;}
inline void Dec(int&a,const int&b){a=a>=b?a-b:a-b+mod;}
inline void Mul(int&a,const int&b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,a=mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=505;
int a[N<<1],f[N<<1][N<<1],n,m=0;
vector<int>pos[N];
int dfs(int l,int r){
	if(l>r)return 1;
	if(~f[l][r])return f[l][r];
	int mn=n+1,s1=0,s2=0;
	for(ri i=l;i<=r;++i)mn=min(mn,a[i]);
	if(pos[mn][0]<l||pos[mn].back()>r)return f[l][r]=0;
	for(ri i=l,up=pos[mn][0];i<=up;++i)Add(s1,mul(dfs(l,i-1),dfs(i,up-1)));
	for(ri i=pos[mn].back(),t=i;i<=r;++i)Add(s2,mul(dfs(t+1,i),dfs(i+1,r)));
	f[l][r]=mul(s1,s2);
	for(ri x=0,y=1,up=pos[mn].size();y<up;++x,++y){
		Mul(f[l][r],dfs(pos[mn][x]+1,pos[mn][y]-1));
		if(!f[l][r])return f[l][r];
	}
	return f[l][r];
}
int main(){
	n=read();
	for(ri tt=read(),col;tt;--tt){
		col=read();
		if(a[m]^col)a[++m]=col,pos[col].push_back(m);
		if(m>2*n)return puts("0"),0;
	}
	memset(f,-1,sizeof(f));
	cout<<dfs(1,m);
	return 0;
}