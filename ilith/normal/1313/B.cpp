#include<bits/stdc++.h>
using namespace std;
long long t;
long long n,x,y;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>x>>y;
		if(x==n&&y==n){
			cout<<n<<' '<<n<<'\n';
			continue;
		}
		cout<<max(x+y+1ll-n,1ll)<<' '<<min(x+y-1ll,n)<<'\n';
	}
	return 0;
}