#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,j,k,n,m;
ll fac[1000010],ans[1000010],len;
int main(){
	cin>>n;
	for(i=1;i*i<=n;i++){
	    if(n%i)continue;
	    len++;
		fac[len]=i;
		len++;
		fac[len]=n/i;
	}
	for(i=1;i<=len;i++)
		ans[i]=(1ll+(n/fac[i]-1)*1ll*fac[i]+1)*n/fac[i]/2;
	sort(ans+1,ans+1+len);
	ans[0] = -23333;
	for(i=1;i<=len;i++)
		if(ans[i]!=ans[i-1])
			printf("%I64d ",ans[i]);
	return 0;
}