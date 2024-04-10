#include<iostream>
using namespace std;
long long n,a,b,i;
int main(){
	cin>>n;
	for(i=1;;i++){
		a+=i;
		b+=a;
		if(b>n){
			cout<<i-1;
			break;
		}
	}
}