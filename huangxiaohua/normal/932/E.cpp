#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t;
ll f[5050][5050],res,pre,p[5050];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

int main(){
	scanf("%d%d",&n,&m);
	f[0][0]=p[0]=1;
	for(i=1;i<=m;i++){
		p[i]=p[i-1]*2%M;
		for(j=1;j<=i;j++){
			f[i][j]=(f[i-1][j-1]*(n-j+1)+f[i-1][j]*j)%M;
		}
	}
	for(i=1;i<=min(n,m);i++){
		res+=f[m][i]*ksm(2,n-i)%M;
	}
	printf("%lld",res%M);
}