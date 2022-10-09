#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve(long long n) {
	if (n == 1) {
		cout << -1;
		return;
	}
	cout << n << ' ' << n+1 << ' ' << n*(n+1);
}

int main() {
	int n;
	cin >> n;
	solve(n);
}