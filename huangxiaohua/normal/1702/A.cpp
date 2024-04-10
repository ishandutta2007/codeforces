#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		ll res=1e10;
		for(ll i=1;i<=n;i*=10)res=min(res,n-i);
		cout<<res<<endl;
	}
}