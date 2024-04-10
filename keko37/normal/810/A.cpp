#include<iostream>

using namespace std;

int n, k, x, sol;

int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> x;
		sol+=(k-x)*2-1;
	}
	if (sol>=0) cout << sol; else cout << 0;
	return 0;
}