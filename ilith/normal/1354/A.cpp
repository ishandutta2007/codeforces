#include<bits/stdc++.h>
using namespace std;
long long t;
long long a,b,c,d;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		if(b>=a){
			cout<<b;
		}
		else if(c<=d){
			cout<<-1;
		}
		else{
			cout<<b+((a-b-1)/(c-d)+1)*c;
		}
		cout<<'\n';
	}
	return 0;
}