#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n < 3) {
			for(int i = 0; i < n; i++) {
				cout << (char)('a' + i);
			}
			cout << '\n';
		}
		else {
			for(int i = 0; i < (n-2)/2; i++) {
				cout << 'a';
			}
			if(n%2) cout << "bc";
			else cout << "b";
			for(int i = 0; i < n/2; i++) {
				cout << 'a';
			}
			cout << '\n';
		}
	}
}