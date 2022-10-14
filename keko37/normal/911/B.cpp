#include<iostream>

using namespace std;

int n, a, b, sol;

int main () {
	cin >> n >> a >> b;
	for (int x=1; x<=min(a, b); x++) {
		if (a/x+b/x>=n) {
			sol=x;
		} else {
			break;
		}
	}
	cout << sol;
	return 0;
}