#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;ll a,b,c,d,need,ev;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		if(a<=b)cout<<b<<"\n";
		else if(c<=d)cout<<"-1\n";
		else{
			need=a-b;ev=c-d;
			cout<<b+(need+ev-1)/ev*c<<"\n";
		}
	}
	return 0;
}