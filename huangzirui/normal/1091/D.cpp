#include<bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
ll i,j,k,n,m;
ll ans[1000010],jc[1000010];
int main(){
	cin>>n;
	jc[1]=1;
	for(i=2;i<=n;i++)jc[i]=jc[i-1]*i%MOD;
	ans[1]=1;
	for(i=2;i<=n;i++)
		ans[i]=((ans[i-1]*i%MOD+jc[i])%MOD-i+MOD)%MOD;
	cout<<ans[n]<<endl;
	return 0;
}