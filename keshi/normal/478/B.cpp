#include <iostream>
using namespace std;
int main(){
	long long int n,k,a,b,x,y;
	cin >> n >> k;
	x=n-k+1;
	b=x*(x-1)/2;
	x=n%k;
	y=n/k;
	a=x*(y*(y+1)/2)+(k-x)*(y*(y-1)/2);
	cout << a << ' ' << b;
	return 0;
}