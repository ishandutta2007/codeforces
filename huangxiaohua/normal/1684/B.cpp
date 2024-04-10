#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	//ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		ll a,b,c;
		cin>>a>>b>>c;
		printf("%lld %lld %lld\n",a+b+c,b+c,c);
	}
}