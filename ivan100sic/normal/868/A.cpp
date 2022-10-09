#include <bits/stdc++.h>
using namespace std;

string pw;
vector<string> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> pw;
	int n;
	cin >> n;
	a.resize(n);
	for (string& s : a) {
		cin >> s;
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			string q = a[i] + a[j];
			if (q.substr(1, 2) == pw || q.substr(0, 2) == pw) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO";
}