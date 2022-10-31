#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
int i,j,k,l,n,m,a[30],i1,i2;
ll res,tmp1,tmp2,dp1[2][405][2][2],dp2[2][405][405][3][3],sum[405],sum2[405][405],no2[30][30],no[30];
inline int su(int a,int b){return (a+b)>M?a+b-M:a+b;}
int main(){
	scanf("%d",&n);
	res=26*26*ksm(25,n-2)%M;
	dp1[0][0][0][0]=625;dp1[0][1][0][1]=25;
	dp1[0][1][1][0]=25;dp1[0][2][1][1]=1;
	for(i=3;i<=n;i++){
		i1=i%2;i2=1-i1;
		for(j=0;j<=(i+9)/2;j++){
			dp1[i1][j][0][0]=(dp1[i2][j][0][0]*24+dp1[i2][j][0][1]*25)%M;
			dp1[i1][j][0][1]=(dp1[i2][j][1][0]*24+dp1[i2][j][1][1]*25)%M;
			dp1[i1][j+1][1][0]=dp1[i2][j][0][0];
			dp1[i1][j+1][1][1]=dp1[i2][j][1][0];
		}
	}
	dp2[0][0][0][0][0]=576;dp2[0][1][0][0][1]=24;dp2[0][0][1][0][2]=24;
	dp2[0][1][0][1][0]=24;dp2[0][2][0][1][1]=1;dp2[0][1][1][1][2]=1;
	dp2[0][0][1][2][0]=24;dp2[0][1][1][2][1]=1;dp2[0][0][2][2][2]=1;
	for(i=3;i<=n;i++){
		i1=i%2;i2=1-i1;
		for(j=0;j<=(i+9)/2;j++){
			for(k=0;k<=(i+9)/2;k++){
				dp2[i1][j][k][0][0]=(dp2[i2][j][k][0][0]*23+dp2[i2][j][k][0][1]*24+dp2[i2][j][k][0][2]*24)%M;
				dp2[i1][j][k][0][1]=(dp2[i2][j][k][1][0]*23+dp2[i2][j][k][1][1]*24+dp2[i2][j][k][1][2]*24)%M;
				dp2[i1][j][k][0][2]=(dp2[i2][j][k][2][0]*23+dp2[i2][j][k][2][1]*24+dp2[i2][j][k][2][2]*24)%M;
				dp2[i1][j+1][k][1][0]=su(dp2[i2][j][k][0][0],dp2[i2][j][k][0][2]);
				dp2[i1][j+1][k][1][1]=su(dp2[i2][j][k][1][0],dp2[i2][j][k][1][2]);
				dp2[i1][j+1][k][1][2]=su(dp2[i2][j][k][2][0],dp2[i2][j][k][2][2]);
				dp2[i1][j][k+1][2][0]=su(dp2[i2][j][k][0][0],dp2[i2][j][k][0][1]);
				dp2[i1][j][k+1][2][1]=su(dp2[i2][j][k][1][0],dp2[i2][j][k][1][1]);
				dp2[i1][j][k+1][2][2]=su(dp2[i2][j][k][2][0],dp2[i2][j][k][2][1]);
			}
		}
	}
	for(i=(n+9)/2;i>=1;i--){
		sum[i]+=sum[i+1];
		for(k=0;k<=1;k++){
			for(l=0;l<=1;l++){
				sum[i]+=dp1[n%2][i][k][l];
			}
		}
		sum[i]%=M;
	}
	for(i=(n+9)/2;i>=1;i--){
		for(j=(n+9)/2;j>=1;j--){
			sum2[i][j]=sum2[i+1][j]+sum2[i][j+1]-sum2[i+1][j+1]+M;
			for(k=0;k<=2;k++){
				for(l=0;l<=2;l++){
					sum2[i][j]+=dp2[n%2][i][j][k][l];
				}
			}
			sum2[i][j]%=M;
		}
	}
	for(i=1;i<=26;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=26;i++){
		no[i]=sum[a[i]+1];
		for(j=1;j<=26;j++){
			if(i==j){continue;}
			no2[i][j]=sum2[a[i]+1][a[j]+1];
			no[i]+=M-no2[i][j];no[i]%=M;
		}
	}
	for(i=1;i<=26;i++){
		res+=M-no[i];
		for(j=i+1;j<=26;j++){
			res+=M-no2[i][j];
		}
	}
	printf("%lld",res%M);
}