#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		cout<<2ll*((1ll<<n)+(1ll<<(n/2))-2)-(1ll<<n+1)+2<<"\n";
	}
	return 0;
}