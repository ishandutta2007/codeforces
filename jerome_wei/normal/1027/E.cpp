#include<bits/stdc++.h>

using namespace std;
const int MOD=998244353;
int t,n;
int f[502][502][2];
int f2[502][502][2];
long long F[502];
int main()
{
	scanf("%d%d",&n,&t);
	//f[1][1][0]
	f[1][1][1]=1;
	for(int i=1;i<=n;i++){
		memset(f2,0,sizeof(f2));
		for(int j=1;j<=i;j++){
			for(int k=1;k<=j;k++){
				f2[j][1][0]+=f[j][k][1];
				f2[j][1][1]+=f[j][k][0];
				
				f2[j][1][0]%=MOD;
				f2[j][1][1]%=MOD;
			}
		}
		for(int j=2;j<=i;j++){
			f2[j][j][0]+=f[j-1][j-1][0];
			f2[j][j][1]+=f[j-1][j-1][1];
			
			f2[j][j][0]%=MOD;
			f2[j][j][1]%=MOD;
		}
		for(int j=2;j<=i;j++){
			for(int k=2;k<=j;k++)
			{
				//cout<<j<<' '<<k<<endl;
				f2[j][k][0]+=f[j][k-1][0];
				f2[j][k][0]%=MOD;
				f2[j][k][1]+=f[j][k-1][1];
				f2[j][k][1]%=MOD;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j][0]=f2[i][j][0],f[i][j][1]=f2[i][j][1];
	}
	for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				F[i]+=f[i][j][0]+f[i][j][1];
				F[i]%=MOD;
			}
			//F[i]/=2;
			//cout<<F[i]<<endl;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n&&i*j<t;j++){
			ans+=1ll*F[i]*F[j]*2;
			ans%=MOD;
			//cout<<i<<j<<endl;
		}
	}
	printf("%lld\n",ans);
}