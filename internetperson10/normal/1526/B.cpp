#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> v;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n < 10) {
			cout << "NO\n";
			continue;
		}
		if(n > 111*11 - 111 - 11) {
			cout << "YES\n";
			continue;
		}
		bool sad = true;
		while(n >= 0) {
			if(!(n%11)) sad = false;
			n -= 111;
		}
		if(sad) cout << "NO\n";
		else cout << "YES\n";
	}
}