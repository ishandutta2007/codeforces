#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(b==1){
			puts("NO");
		}
		else{
			puts("YES");
			cout<<a<<' '<<a*b*2-a<<' '<<a*b*2<<'\n';
		}
	}
	return 0;
}