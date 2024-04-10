#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
const int N=3010;
int n,c;
int a[N];

namespace Sol1{
	int f[N][N],dp[N][303],s[N][303];
	int pw[N],inver[N],cnt[N];
	void doit(){
		pw[0]=1;for(int i=1;i<=n;i++)pw[i]=mul(pw[i-1],2);
		for(int i=0;i<=n;i++)inver[i]=qpow(pw[i]-1,mod-2);
		for(int i=1;i<=n;i++){
			memset(cnt,0,sizeof(cnt));
			int val=1,exist=0;
			for(int j=i;j<=n;j++){
				if(a[j]==a[i]){
					if(!cnt[a[i]])++exist, ++cnt[a[i]];
					else{
						++cnt[a[i]];
						val=add(val,val);
					}
				}else{
					if(!cnt[a[j]])++exist,++cnt[a[j]];
					else{
						val=mul(val,inver[cnt[a[j]]]);
						++cnt[a[j]];
						val=mul(val,pw[cnt[a[j]]]-1);
					}
				}
				if(a[i]!=a[j]&&exist==c){
					f[i][j]=mul(val,inver[cnt[a[j]]]);
				}
			}
		}
		dp[n+1][0]=1,s[n+1][0]=1;
		for(int i=n;i;i--){
			int sum=0;
			for(int j=1;j<=(n-i+1)/c;j++){
				for(int k=i+c-1;k<=n&&s[k+1][j-1];k++){
					dp[i][j]=add(dp[i][j],mul(f[i][k],s[k+1][j-1]));
				}
				sum=add(sum,dp[i][j]);
				s[i][j]=add(s[i+1][j],dp[i][j]);
			}
			dp[i][0]=add(pw[n-i],mod-sum);
			s[i][0]=add(s[i+1][0],dp[i][0]);
		}
		--s[1][0];
		for(int i=0;i<=n/c;i++){
			printf("%d ",s[1][i]);
		}
		for(int i=n/c+1;i<=n;i++)printf("%d ",0);puts("");
	}
}

namespace Sol2{
	int dp[2][N][1<<10];
	void doit(){
		int cur=0;
		dp[0][0][0]=1;
		int lim=(1<<c)-1;
		for(int i=0;i<n;i++){
			cur^=1;
			memset(dp[cur],0,sizeof(dp[cur]));
			for(int j=0;j<=i/c;j++){
				for(int s=0;s<(1<<c);s++)if(dp[cur^1][j][s]){
					int v=dp[cur^1][j][s];
					dp[cur][j][s]=add(dp[cur][j][s],v);
					if((s|(1<<(a[i+1]-1)))==lim)dp[cur][j+1][0]=add(dp[cur][j+1][0],v);
					else dp[cur][j][s|(1<<(a[i+1]-1))]=add(dp[cur][j][s|(1<<(a[i+1]-1))],v);
				}
			}
		}
		for(int i=0;i<=n;i++){
			int ans=0;
			for(int s=0;s<(1<<c);++s){
				ans=add(ans,dp[cur][i][s]);
			}
			if(i==0)ans=sub(ans,1);
			printf("%d ",ans);
		}
		puts("");
	}
}

int main()
{
	cin >> n >> c;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(c==1){
		int val=1,Fac=1;
		printf("0 ");
		for(int i=1;i<=n;i++){
			Fac=mul(Fac,i);
			val=mul(val,n-i+1);
			printf("%d ",mul(val,qpow(Fac,mod-2)));
		}
	}
	else if(c<=10)Sol2::doit();
	else Sol1::doit();
}