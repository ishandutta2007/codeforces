#include<iostream>

using namespace std;

long long n;
long long sol;

int main () {
	cin >> n;
	long long x=n;
	long long y=9;
	long long z=0;
	long long i=1;
	while (x) {
		z+=y;
		sol+=y*i;
		x/=10;
		i++;
		y*=10;
	}
	sol=sol-y/10*(i-1)+(n-z/10)*(i-1);
	cout << sol;
	return 0;
}