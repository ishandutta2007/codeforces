#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	size_t sol = 0;

	for (int l=0; l<n; l++) {
		set<char> sk;
		for (int r=l; r<n; r++) {
			if (isupper(s[r])) {
				break;
			}
			sk.insert(s[r]);
			sol = max(sol, sk.size());
		}
	}

	cout << sol;
}