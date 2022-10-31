#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[2];

int main() {
	//ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		if(m==1){
			cout<<"YES\n";
			for(i=1;i<=n;i++){
				cout<<i<<'\n';
			}
			continue;
		}
		if(n&1){
			cout<<"NO\n";continue;
		}
		cout<<"YES\n";
		f[1]=1;f[0]=2;
		for(i=0;i<n;i++){
			for(j=1;j<=m;j++){
				cout<<f[i&1]<<' ';
				f[i&1]+=2;
			}
			cout<<'\n';
		}
	}
}