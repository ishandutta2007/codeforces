#include<bits/stdc++.h>
using namespace std;
int n,s;
int main(){
	cin>>n>>s;
	if(n>s/2)cout<<"NO";
	else{
		cout<<"YES\n";
		for(int i=1;i<n;++i)cout<<2<<" ",s-=2;cout<<s<<"\n";
		cout<<1;
	}
}