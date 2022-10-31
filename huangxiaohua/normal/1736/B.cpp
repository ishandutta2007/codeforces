#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a[1000005],b[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>b[i];
		}
		for(i=2;i<=n;i++){
			a[i]=b[i]*b[i-1]/__gcd(b[i],b[i-1]);
		}
		for(i=2;i<n;i++){
			if(b[i]!=__gcd(a[i],a[i+1])){
				cout<<"NO\n";goto aaa;
			}
		}
		cout<<"YES\n";
		aaa:;
	}
}