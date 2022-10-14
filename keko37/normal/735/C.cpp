#include<iostream>

using namespace std;

typedef long long llint;

llint n, m;
llint fib[1005];

int main () {
	cin >> n;
	fib[0]=1;
	fib[1]=1;
	for (int i=2; i<=1000; i++) {
		fib[i]=fib[i-1]+fib[i-2];
		if (fib[i]>n) {
			cout << i-2;
			break;
		}
	}
	return 0;
}