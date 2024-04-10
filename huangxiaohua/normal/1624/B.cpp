#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>i>>j>>k;
		sb=j+j-k;
		if(i<=sb&&!(sb%i)){
			cout<<"YES\n";continue;
		}
		sb=j+j-i;
		if(k<=sb&&!(sb%k)){
			cout<<"YES\n";continue;
		}
		if((i+k)&1){
			
		}
		else{
			sb=(i+k)/2;
			if(j<=sb&&!(sb%j)){
				cout<<"YES\n";continue;
			}
		}
		cout<<"NO\n";
	}
}