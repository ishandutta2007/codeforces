#include<iostream>

using namespace std;

int n, k, sol=10000, x;

int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> x;
		if (k%x==0) sol=min(sol, k/x);
	}
	cout << sol;
	return 0;
}