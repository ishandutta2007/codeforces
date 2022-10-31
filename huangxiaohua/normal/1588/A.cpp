#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[666],b[666];

int main() {
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++)cin>>b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(i=1;i<=n;i++){
			if((a[i]-b[i])!=0&&(a[i]-b[i])!=-1){
				cout<<"NO\n";goto aaa;
			}
		}
		cout<<"YES\n";
		aaa:;
	}
}