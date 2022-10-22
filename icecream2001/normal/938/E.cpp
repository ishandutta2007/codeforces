#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
#define N 1000050
using namespace std;
int n;
LL mod=1000000007,ans=0;
LL a[N],b[N],jc[N],ny[N];
bool cmp(LL A,LL B){
	return A>B;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+1+n,cmp);
	ny[0]=1;jc[0]=1;
	ny[1]=1;jc[1]=1;
	for(LL i=2;i<=n;i++){
		ny[i]=(mod-mod/i)*ny[mod%i]%mod;
	}
	for(LL i=2;i<=n;i++){
		ny[i]=ny[i-1]*ny[i]%mod;
		jc[i]=jc[i-1]*i%mod;
	}
	int cnt=1;LL tot=0;b[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]) b[cnt]++;
		else {
			a[++cnt]=a[i];b[cnt]=1;
		}
	}
	tot=b[1];
	for(int i=2;i<=cnt;i++){
		tot+=b[i];
		ans=(ans+jc[n]*ny[tot]%mod*ny[n-tot]%mod*jc[tot-1]%mod*a[i]%mod*b[i]%mod*jc[n-tot]%mod)%mod;
	}
	printf("%I64d\n",ans);
	return 0;
}