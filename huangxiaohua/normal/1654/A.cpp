#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,t,n,m,a[66666],sb;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		cout<<a[n]+a[n-1]<<'\n';
	}
}