#include<iostream>

using namespace std;

typedef long long llint;

llint n, lim, pot=1, sol;

int main () {
	cin >> n;
	lim=n+n-1;
	while (1) {
		if (pot*10-1<=lim) {
			pot*=10;
		} else {
			break;
		}
	}
	for (int i=0; i<10; i++) {
		llint val=i*pot+pot-1;
		if (val>lim) break;
		llint x=max(val-n, 1LL);
		llint y=min(val-1, n);
		sol+=(y-x+1)/2;
	}
	cout << sol;
	return 0;
}