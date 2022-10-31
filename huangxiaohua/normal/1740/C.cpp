#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a[1005000];
ll res;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		res=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		res=a[n]-a[1];
		for(i=1;i+1<n;i++){
			res=max(res,a[n]+a[i+1]-a[i]-a[i]);
		}
		for(i=n;i>2;i--){
			res=max(res,a[i]+a[i]-a[i-1]-a[1]);
		}
		cout<<res<<'\n';
	}
}