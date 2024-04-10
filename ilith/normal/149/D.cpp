#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define fi first
#define se second
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=710,mod=1000000007;
ll n,p[N],dp[N][N][3][3];
char s[N];
int q[N],hd,ans;
ll dfs(int l,int r,int cl,int cr){
	if(~dp[l][r][cl][cr])return dp[l][r][cl][cr];
	if(r-l<=1)return 0;
	if(p[l]==r){
		if((cl&&cr)||(!cl&&!cr))return 0;
		int res=0;
		for(rgi L=0;L<3;++L)for(rgi R=0;R<3;++R){
			if(L!=cl||!L)if(R!=cr||!R)(res+=dfs(l+1,r-1,L,R))%=mod;
		}
		return dp[l][r][cl][cr]=res;
	}
	int k=p[l],res=0;
	for(rgi L=0;L<3;++L)if((!!L+!!cl)==1)for(rgi R=0;R<3;++R){
		if(L!=R||!L)(res+=dfs(l,k,cl,L)*dfs(k+1,r,R,cr)%mod)%=mod;
	}
	return dp[l][r][cl][cr]=res;
}	
signed main(){
	memset(dp,-1,sizeof dp);
	scanf("%s",s+1),n=strlen(s+1);
	for(rgi i=1;i<=n;++i){
		if(s[i]=='(')q[++hd]=i;
		else p[i]=q[hd],p[q[hd--]]=i;
		dp[i][i][0][0]=dp[i][i][1][1]=dp[i][i][2][2]=1;
	}
	for(rgi i=1;i<n;++i){
		int j=i+1;
		for(rgi nl=0;nl<3;++nl)for(rgi nr=0;nr<3;++nr){
			if(nl!=nr||!nl||!nr)dp[i][j][nl][nr]=1;
		}
		if(p[j]==i)dp[i][j][0][0]=dp[i][j][1][1]=dp[i][j][2][2]=dp[i][j][1][2]=dp[i][j][2][1]=0;
	}
	for(rgi nl=0;nl<3;++nl)for(rgi nr=0;nr<3;++nr)(ans+=dfs(1,n,nl,nr))%=mod;
	write(ans);
	return 0;
}