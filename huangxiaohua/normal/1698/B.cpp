#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],res;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++)cin>>a[i];
		res=0;
		for(i=2;i<n;i++){
			res+=(a[i]>a[i-1]+a[i+1]);
		}
		if(m==1){
			res=(n-1)/2;
		}
		cout<<res<<'\n';
	}
}