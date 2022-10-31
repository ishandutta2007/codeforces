#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,l,r;
ll c[4050][4050],s[4050][4050],sum[4050],res=1;

int main(){
	c[0][0]=s[0][0]=1;
	for(i=1;i<=4000;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
			s[i][j]=(s[i-1][j-1]+s[i-1][j]*j)%M;
			sum[i]=(sum[i]+s[i][j])%M;
		}
	}
	scanf("%d",&n);
	for(i=1;i<n;i++){
		res+=c[n][i]*sum[i]%M;
	}
	printf("%lld",res%M);
}