#include<iostream>
using namespace std;
int main(){
	int n,k;cin>>n>>k;
	if(k>n/2)
		cout<<n-k;
	else{
		if(k==0){cout<<1;return 0;}
		cout<<k;
	}
}