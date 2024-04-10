#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,mx,mn;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		mx=-1;
		mn=2e9;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>k;
			mx=max(mx,k);
			mn=min(mn,k);
		}
		cout<<mx-mn<<'\n';
	}
}