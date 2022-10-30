// Hydro submission #61daa380b672efeeab31743c@1641718657555
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,d,b;
long long a[N];
int main(){
	scanf("%d%d%d",&n,&d,&b);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]+=a[i-1];
	int mi=(n+1)/2,s1=0,s2=0;
	for(int i=1;i<=mi;i++)if(a[min(1ll*n,1ll*i*(d+1))]-1ll*s1*b>=b)s1++;
	for(int i=1;i<=n-mi;i++)if(a[n]-a[max(0ll,n-1ll*i*(d+1))]-1ll*s2*b>=b)s2++;
	printf("%d",max(mi-s1,n-mi-s2));
}