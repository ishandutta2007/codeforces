#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,x,j=0,k=10009;cin>>n;
	while(n--){
		cin>>x;
		if(x>0) j+=x;
		if(abs(x)%2==1)
		k=min(k,abs(x));}
	if(j%2==1)k=0;
	cout<<j-k;
}