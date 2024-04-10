#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,b[200500];
ll a[200500],s1,s0,f0[3050][3050],f1[3050][3050],res,sum0,sum1;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

int main() {
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(b[i]){s1+=a[i];}
		else{s0+=a[i];}
	}
	f0[0][0]=f1[0][0]=1;
	for(i=0;i<=m;i++){
		for(j=0;j<=i;j++){
			f0[i][j]%=M;
			f0[i+1][j]+=f0[i][j]*(s1+(i-j))%M*ksm(s0-j+s1+(i-j),M-2);
			if(j<s0){
				f0[i+1][j+1]+=f0[i][j]*(s0-j)%M*ksm(s0-j+s1+(i-j),M-2);
			}
			
			f1[i][j]%=M;
			f1[i+1][j+1]+=f1[i][j]*(s1+j)%M*ksm(s0-(i-j)+s1+j,M-2);
			if(i-j<s0){
				f1[i+1][j]+=f1[i][j]*(s0-(i-j))%M*ksm(s0-(i-j)+s1+j,M-2);
			}
		}
	}
	for(i=1;i<=m;i++){
		sum1+=i*ksm(s1,M-2)%M*f1[m][i]%M;
		sum0+=i*ksm(s0,M-2)%M*f0[m][i]%M;
	}
	sum1%=M;sum0=(-sum0%M+M)%M;
	for(i=1;i<=n;i++){
		res=0;
		if(b[i]){
			printf("%lld\n",a[i]*(1+sum1)%M);
		}
		else{
			printf("%lld\n",a[i]*(1+sum0)%M);
		}
	}
}