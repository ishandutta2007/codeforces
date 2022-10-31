#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll x,y,z;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>x>>y>>z;
		if(x>(y+z+1)||y>(x+z+1)||z>(x+y+1)){
			cout<<"No\n";
		}
		else{
			cout<<"Yes\n";
		}
	}
}