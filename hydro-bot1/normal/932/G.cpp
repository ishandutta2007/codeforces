// Hydro submission #62a53c47cd1ee6a7e16b3a2c@1654996040334
#include<bits/stdc++.h>
#include<bits/extc++.h>
#pragma GCC optimize(2)
using namespace std;
#define map __gnu_pbds::gp_hash_table
#define re register
typedef double db;
typedef long long ll;
inline int win(){
	int x=0,w=0;char c=getchar();
	while(c>'9'||c<'0') w|=c=='-',c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return w?-x:x;
}

namespace pam{
	const int N=505505;const int mod=1000000007;
	inline void md(int &x,int &y){if((x+=y)>=mod) x-=mod;}
	int n,s[N],tot,la,fa[N],len[N],df[N],gf[N];map<int,int> ch[N];int f[N],g[N];

	inline void out(){printf("%d\n",f[n]);}
	inline void init(){f[0]=1,s[0]=1145141919,n=la=0,tot=1,len[1]=-1,len[0]=0,fa[0]=1;}
	inline int ffa(int x,int i){while(s[i]!=s[i-len[x]-1]) x=fa[x];return x;}

	inline void ext(int c){
		s[++n]=c;int x=ffa(la,n);
		if(ch[x].find(c)!=ch[x].end()) la=x=ch[x][c];
		else{
			fa[++tot]=ch[ffa(fa[x],n)][c],len[ch[x][c]=tot]=len[x]+2,la=x=ch[x][c];
			df[x]=len[x]-len[fa[x]],gf[x]=(df[x]!=df[fa[x]])?x:gf[fa[x]];
		}
		for(re int y=gf[x];x>1;x=fa[y],y=gf[x]){
			g[x]=f[n-len[y]];
			if(y!=x) md(g[x],g[fa[x]]);
			md(f[n],g[x]);
		}
	}
};

const ll bs=131ll,mod=167772161ll;
char s[1010101];
map<ll,int> id;
signed main(){
	pam::init(),scanf("%s",s+1);
	int n=strlen(s+1);ll hsa=0,hsb=0,pw=1;
	for(re int i=1,j=n,cnt=0;i<=j;++i,--j){
		hsa=(hsa*bs+s[i]-'a'+37)%mod,hsb=(hsb+(s[j]-'a'+37)*pw)%mod,pw=pw*bs%mod;
		if(hsa==hsb) pam::ext(id.find(hsa)!=id.end()?id[hsa]:(id[hsa]=++cnt)),hsa=0,hsb=0,pw=1;
	}
	if(hsa!=hsb) return puts("0"),0;
	pam::out();
	return 0;
}