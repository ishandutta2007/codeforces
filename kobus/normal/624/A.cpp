#include<iostream>
using namespace std;
 
int main(){
	long double d,l,v1,v2;
	cin>>d>>l>>v1>>v2;
	long double a,b,c;
	a=(l-d);
	b=1/(v1+v2);
	c=a*b;
	cout.precision(7);
  cout.setf(ios::fixed);
	cout<<c<<"\n";
	return 0;
 
}