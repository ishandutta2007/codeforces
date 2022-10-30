// Hydro submission #61bc809d4101257825755013@1639743645756
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];
long long ans;
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1])ans+=1ll*(a[i]-a[i-1])*(n-a[i]+1);
		else ans+=1ll*a[i]*(a[i-1]-a[i]);
	}
	cout<<ans;
}