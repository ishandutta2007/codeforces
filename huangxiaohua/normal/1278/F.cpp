#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,m2;
ll f[5050][5050],res;

ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

int main(){
	f[0][0]=1;
    scanf("%d%d%d",&n,&m,&k);
    m=ksm(m,M-2);
    for(i=1;i<=5000;i++){
    	for(j=1;j<=i;j++){
    		f[i][j]=(f[i-1][j-1]*(n-j+1)+f[i-1][j]*j)%M;
		}
	}
	for(i=1;i<=k;i++){
		res+=f[k][i]*ksm(m,i)%M;
	}
	printf("%lld",res%M);
}