#include <bits/stdc++.h>
using namespace std;

long long n, q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while(n--) {
		cin >> q;
		if(180 - __gcd(180ll, q) > q) {
			cout << 180/__gcd(180ll, q);
		} else {
			cout << 180/__gcd(180ll, q) * 2;
		}
		cout << "\n";
	}
}