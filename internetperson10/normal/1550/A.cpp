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
		for(int i = 0; i <= n; i++) {
			if(i*i >= n) {
				cout << i << "\n";
				break;
			}
		}
	}
}