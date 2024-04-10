#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--) {
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a!=c&&b!=d) cout<<abs(a-c)+abs(b-d)+2<<endl;
		else cout<<abs(a-c)+abs(b-d)<<endl;
	}
	return 0;
}