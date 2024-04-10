#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t,sb[100500];
ll jc[1005000],inv[1005000],a[1005000],res;

int main(){
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=397802501;
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		k++;
		if(a[i]!=a[i+1]&&a[i+1]){
			res+=k*a[i]%M*jc[n-i+k-1]%M*jc[n]%M*inv[n-i+k]%M;k=0;
		}
	}
	printf("%lld",res%M);
}