#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k = 0;
		cin >> n;
		for(int i = 0; i < 2*n; i++) {
			int x;
			cin >> x;
			if(x%2) k++;
		}
		cout << ((k == n) ? "Yes\n" : "No\n");
	}
}