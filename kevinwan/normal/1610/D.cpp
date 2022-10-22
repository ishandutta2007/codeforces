#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e9+7;
const int mn = 2e5+10;
int a[mn],num[30];
ll p2[mn];
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		num[__builtin_ctz(a[i])]++;
	}
	p2[0]=1;
	for(int i=1;i<=n;i++)p2[i]=p2[i-1]*2%mod;
	int rem=n-num[0];
	ll ans=p2[n]-1;
	for(int i=1;i<30;i++){
		if(num[i]>0){
			ans-=p2[num[i]-1]*p2[rem-num[i]];
			ans%=mod;
		}
		rem-=num[i];
	}
	if(ans<0)ans+=mod;
	printf("%lld\n",ans);
}