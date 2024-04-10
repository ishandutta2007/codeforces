#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	int p;
	cin >> p;
	for(int i=1; ; ++i) {
		long long x=n-i*p;
		if(x < 0) {
			cout << -1;
			break;
		}
		if(i<=x&&__builtin_popcount(x)<=i) {
			cout << i;
			break;
		}
	}

	return 0;
}