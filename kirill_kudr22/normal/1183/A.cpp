#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f(int n) {
	int x = 0;
	while(n) {
		x += n % 10;
		n /= 10;
	}
	if(x % 4 == 0) {
		return true;
	}
	return false;
}
signed main() {
	int n;
	cin >> n;
	while(! f(n)) {
		n++;
	}
	cout << n;
}