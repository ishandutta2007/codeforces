#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;k=0;
		for(i=1;i<=n;i++){
			cin>>j;k+=j;
		}
		if(k)cout<<"YES\n";
		else cout<<"NO\n";
	}
}