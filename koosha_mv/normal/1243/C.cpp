#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	long long p,n,m=0,t=0,gc;
	cin>>n;gc=n;
	p=n;
	for(long long i=2;i*i<=n;i++){
		if(n%i==0){
			gc=__gcd(gc,i);
			gc=__gcd(gc,n/i);
		}
	}	
	cout<<gc;
}