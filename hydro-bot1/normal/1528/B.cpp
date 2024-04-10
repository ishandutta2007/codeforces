// Hydro submission #622044eb054daa82758fc6bb@1646281963418
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=998244353;
int n,s[N],f[N],sum[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)s[j]++;
	for(int i=1;i<=n;i++)f[i]=(sum[i-1]+s[i])%mod,sum[i]=(sum[i-1]+f[i])%mod;
	printf("%d",f[n]);
}