#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll x,y;

int main() {
	//ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>x>>y;
		for(i=1;i<=n;i++){
			cin>>k;x^=k;
		}
		if((x&1)==(y&1)){
			cout<<"Alice\n";
		}
		else cout<<"Bob\n";
	}
}