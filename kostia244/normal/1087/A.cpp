#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	string b;

	if (s.size() & 1) {
		int curr = s.size() - 1;
		int curl = 0;
		while (curl < curr) {
			b += s[curl];
			curl++;
			b += s[curr];
			curr--;
		}b += s[curl];
		curl++;

	} else {
		int curr = s.size() - 1;
		int curl = 0;
		while (curl < curr) {
			b += s[curr];
			curr--;
			b += s[curl];
			curl++;
		}
	}
	reverse(b.begin(), b.end());
	cout << b;


}