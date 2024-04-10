#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[510000];
priority_queue<ll> q;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for (int i=1;i<=k+1;i++) q.push(0);
	ll ans=0;
	for (int i=1;i<=n;i++){
		ll u=q.top(); q.pop();
		ans+=u; u+=a[i]; q.push(u);
	}
	printf("%lld\n",ans);
	return 0;
}