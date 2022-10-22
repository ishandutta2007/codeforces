#include<bits/stdc++.h>
using namespace std;
int main() {
	long long t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		k*=((n-1)/k+1);
		cout<<(k/n)+(k%n!=0)<<'\n';
	}
	return 0;
}