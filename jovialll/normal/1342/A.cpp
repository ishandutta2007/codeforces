#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a,b,x,y;
signed main(){
	cin>>t;
	while(t--){
		cin>>x>>y>>a>>b;
		if(a+a<=b){
			cout<<(x+y)*(a)<<"\n";
		}
		else{
			cout<<min(x,y)*b+(max(x,y)-min(x,y))*a<<"\n";
		}
	}
	 return 0;
}