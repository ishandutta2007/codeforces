#include <iostream>
using namespace std;
int main(){
	int a,b,x,y=6;
	cin >> a >> b;
	x=7-max(a,b);
	if (x%2==0){
		x/=2;
		y/=2;
	}
	if (x%3==0){
		x/=3;
		y/=3;
	}
	cout << x << '/' << y;
	return 0;
}