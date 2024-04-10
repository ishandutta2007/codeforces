#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,a[5050],it;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll inv[5050],sb,pre[5050][5050],res;
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
int main(){
	pre[0][0]=1;
	for(i=0;i<=5005;i++){inv[i]=ksm(i,M-2);}
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&k);a[k]++;}
	for(i=1;i<=n;i++){
		if(!a[i]){continue;}
		it++;pre[it][0]=1;
		for(j=1;j<=i;j++){
			sb=pre[it-1][j-1]*inv[n-j+1]%M*a[i]%M;
			res=su(res,sb*inv[n-j]%M*(a[i]-1)%M);
			pre[it][j]=su(pre[it-1][j],sb);
		}
	}
	printf("%lld",res%M);
}