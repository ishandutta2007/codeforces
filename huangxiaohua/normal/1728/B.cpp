#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a,b;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		if(n&1){
			cout<<"1 2 3 ";
			for(i=5;i<n;i+=2){
				cout<<i<<' '<<i-1<<' ';
			}
			cout<<n-1<<' '<<n<<'\n';
		}
		else{
			for(i=2;i<n;i+=2){
				cout<<i<<' '<<i-1<<' ';
			}
			cout<<n-1<<' '<<n<<'\n';
		}
	}
}