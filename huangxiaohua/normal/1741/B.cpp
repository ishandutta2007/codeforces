#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==3){
			cout<<"-1\n";continue;
		}
		if(n&1){
			cout<<n<<' '<<n-1<<' ';
			for(i=1;i<=n-2;i++){
				cout<<i<<' ';
			}
		}
		else{
			for(i=n;i>=1;i--)cout<<i<<' ';
		}
		cout<<'\n';
	}
}