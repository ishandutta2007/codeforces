#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		if(n&1){
			cout<<"-1\n";
		}
		else{
			cout<<n/2<<' '<<0<<' '<<0<<' '<<endl;
		}
	}
}