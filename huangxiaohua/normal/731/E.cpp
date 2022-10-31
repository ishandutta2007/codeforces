#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,a[200500];
ll f[200500][2],mx=-1e18,mn=1e18,pre[200500];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=pre[i-1]+a[i];
	}
	mn=-pre[n];
	mx=pre[n];
	for(i=n-1;i>=1;i--){
		f[i][0]=mx;
		f[i][1]=mn;
		mx=max(f[i][1]+pre[i],mx);
		mn=min(f[i][0]-pre[i],mn);
	}
	printf("%lld",f[1][0]);
}