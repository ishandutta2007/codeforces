#include<bits/stdc++.h>
using namespace std; 
int t;
int n;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cout<<4*n-2*i<<' ';
		}
		cout<<'\n';
	}
	return 0;
}