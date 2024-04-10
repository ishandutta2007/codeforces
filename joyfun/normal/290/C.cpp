#include<iostream>
using namespace std;
int main(){
	int i,n;
	double a,b=0,mx=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a;
		b+=a;
		mx=max(mx,b/i);
	}
	cout<<mx<<endl;
}