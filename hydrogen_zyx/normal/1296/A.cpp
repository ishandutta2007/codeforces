#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ji = 0, ou = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if (a & 1) ji = 1;
			else ou = 1;
			sum += a;
		}
		if (sum & 1) cout << "YES" << endl;
		else {
			if (ji && ou) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}