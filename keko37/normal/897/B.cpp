#include<iostream>

using namespace std;

long long k, p, sol;

long long f (int x) {
	long long val=0, pot=1, org=x;
	while (x) {
		val=val*10+x%10;
		x/=10;
		pot*=10;
	}
	return org*pot+val;
}

int main () {
	cin >> k >> p;
	for (int i=1; i<=k; i++) {
		sol+=f(i)%p;
	}
	cout << sol%p;
	return 0;
}