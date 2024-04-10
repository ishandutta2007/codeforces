#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t;
ll c[305][305],f[305],t1;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
int main(){
	c[0][0]=1;
	for(i=1;i<=300;i++){
		c[i][0]=1;for(j=1;j<=i;j++){c[i][j]=su(c[i-1][j-1],c[i-1][j]);}
	}
	scanf("%d%d",&n,&m);
	for(i=n-1;i>=0;i--){
		f[i]=su(c[n][i]*ksm(m-1,i*n)%M*ksm(su(ksm(m,n-i),M-ksm(m-1,n-i)),n)%M,M-f[i+1]);
	}
	printf("%lld",f[0]);
}