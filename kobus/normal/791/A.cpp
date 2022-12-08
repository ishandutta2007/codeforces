#include <iostream>
#include <cmath>

using namespace std;


int main(){

	int a,b,n=0;
	cin>>a>>b;

	while(a<=b){

		n=n+1;
		a=3*a;
		b=2*b;
	}
	
	cout<<n<<"\n";

	return 0;
}