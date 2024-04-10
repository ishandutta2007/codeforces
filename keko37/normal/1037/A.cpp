#include<iostream>

using namespace std;

int n, sol, val = 1;

int main () {
	cin >> n;
	while (val <= n) {
		val *= 2;
		sol++;
	}
	cout << sol;
	return 0;
}