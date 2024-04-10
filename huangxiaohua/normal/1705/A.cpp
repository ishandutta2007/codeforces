#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005000];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n+n;i++)cin>>a[i];
		sort(a+1,a+n+n+1);
		for(i=1;i<=n;i++){
			if(a[n+i]-a[i]<m){
				cout<<"No\n";goto aaa;
			}
		}
		cout<<"Yes\n";
		aaa:;
	}
}