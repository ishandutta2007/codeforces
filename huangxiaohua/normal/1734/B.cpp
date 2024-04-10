#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a[666],res;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++){
				if(j==1||j==i)cout<<"1 ";
				else cout<<"0 ";
			}
			cout<<'\n';
		}
	}
}