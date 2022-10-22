#include<bits/stdc++.h>
#define rgi register int
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
const int N=170,mod=51123987;
int n,nxt[N][3],lim,dp[N][53][53][53],ans;
char s[N];
signed main(){
	read(n),scanf("%s",s+1);
	lim=(n+2)/3,nxt[n+1][0]=nxt[n+1][1]=nxt[n+1][2]=n+1;
	for(rgi i=n;i;--i){
		for(rgi j=0;j<3;++j)nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i]-'a']=i;
	}
	dp[1][0][0][0]=1;
	for(rgi w=1;w<=n;++w){
		for(rgi i=0;i<=lim;++i){
			for(rgi j=0;j<=lim;++j){
				for(rgi k=0;k<=lim;++k){
					if(i+j+k==n&&abs(i-j)<=1&&abs(j-k)<=1&&abs(i-k)<=1){
						(ans+=dp[w][i][j][k])%=mod;
						continue;
					}
					(dp[nxt[w][0]][i+1][j][k]+=dp[w][i][j][k])%=mod;
					(dp[nxt[w][1]][i][j+1][k]+=dp[w][i][j][k])%=mod;
					(dp[nxt[w][2]][i][j][k+1]+=dp[w][i][j][k])%=mod;
				}
			}
		}
	}
	write(ans);
	return 0;
}