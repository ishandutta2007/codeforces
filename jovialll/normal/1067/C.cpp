#include<bits/stdc++.h>
using namespace std;
int n,i,g;
int main(){
	cin>>n;
	if(n<11){
		for(i=1;i<=n;++i)cout<<i<<" 0\n";
		return 0;
	}
	if(n<13){
		for(i=1;i<=(n>>1);++i)cout<<i<<" 0\n";
		for(i=1;i<=(n>>1);++i)cout<<i<<" 1\n";
		if(n&1)cout<<"10000 10000\n";
		return 0;
	}
	g=n/3;
	if(n%3==1){
		
	for(i=0;i<g;++i){
		cout<<i*2+1<<" 0\n";
		cout<<i*2+2<<" 1\n";
		cout<<i*2+2<<" -1\n";
	}
	cout<<g*2+1<<" 0\n";
	}
	if(n%3==0){
		
	for(i=0;i<g;++i){
		cout<<i*2+1<<" 0\n";
		cout<<i*2+2<<" 1\n";
		cout<<i*2+2<<" -1\n";
	}
	} 
	if(n%3==2){
		cout<<"0 1\n0 -1\n";
	for(i=0;i<g;++i){
		cout<<i*2+1<<" 0\n";
		cout<<i*2+2<<" 1\n";
		cout<<i*2+2<<" -1\n";
	}
	}
}