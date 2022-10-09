// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector<int> b;
		s += '0';
		int l = 0;
		for (char c : s) {
			if (c == '0') {
				b.push_back(l);
				l = 0;
			} else {
				l++;
			}
		}
		int z = 0;
		sort(begin(b), end(b), greater<int>());
		for (int i=0; i<(int)b.size(); i+=2) {
			z += b[i];
		}
		cout << z << '\n';
	}
}