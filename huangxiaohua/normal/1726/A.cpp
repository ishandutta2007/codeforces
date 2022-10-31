#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a[2050],res,b[2050];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		if(n==1){
			cout<<"0\n";continue;
		}
		res=a[n]-a[1];
		for(i=2;i<=n;i++){
			res=max(res,a[i-1]-a[i]);
		}
		sort(a+1,a+n);
		sort(b+2,b+n+1);
		res=max(res,a[n]-a[1]);
		res=max(res,b[n]-b[1]);
		cout<<res<<'\n';
	}
}