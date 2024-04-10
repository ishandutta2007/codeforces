#include<iostream>
using namespace std;
int l,r,n,c,t,m,z,ans;

int main(){

	cin>>n>>t>>c;
	for(int i=0; i<n;i++){
		cin>>m;
		if (m<=t) {z++; 
			if (z>=c) ans++;
		}else z=0;

	}
	cout<<ans;
return 0;
}