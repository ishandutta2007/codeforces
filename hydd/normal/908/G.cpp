#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int n,ans,a[710],dp[710][710][10][2];
char s[710];
inline int ADD(int x){
	if (x>=Mod) x-=Mod;
	return x;
}
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n;i++) a[i]=s[i]-'0';
	for (int k=1;k<=9;k++){
		memset(dp[0],0,sizeof(dp[0]));
		int now=0;
		for (int i=0;i<=9;i++) dp[0][0][i][1]=1;
		for (int i=0;i<n;i++){
			memset(dp[now^1],0,sizeof(dp[now^1]));
			for (int j=0;j<=i;j++)
				for (int l=0;l<=1;l++){
					int lim=l?a[i+1]:9;
					for (int x=0;x<=lim;x++)
						dp[now^1][j+(x>=k)][k][l&(x==lim)]=ADD(dp[now^1][j+(x>=k)][k][l&(x==lim)]+dp[now][j][k][l]);
				}
			now^=1;
		}
		int x=1;
		for (int i=1;i<=n;i++){
			ans=ADD(ans+(ll)x*(dp[now][i][k][0]+dp[now][i][k][1])%Mod);
			x=(x*10ll+1)%Mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}