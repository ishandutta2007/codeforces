#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a[100500],res;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>t;
	for(i=1;i<=n+1;i++){
		res+=i*(n+1-i);
	}
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]){
			res-=(n-i+1)*(i-1);
		}
	}
	while(t--){
		ll x,y;
		cin>>x>>y;
		if(a[x]==a[x-1]){
			res+=(n-x+1)*(x-1);
		}
		if(a[x]==a[x+1]){
			res+=(n-x)*x;
		}
		a[x]=y;
		if(a[x]==a[x-1]){
			res-=(n-x+1)*(x-1);
		}
		if(a[x]==a[x+1]){
			res-=(n-x)*x;
		}
		cout<<res<<'\n';
	}
}