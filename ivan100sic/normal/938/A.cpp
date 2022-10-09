#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string v = "aeiouy";
	int n;
	cin >> n;
	string s, p;
	cin >> s;
	for (char x : s) {
		if (p.size() && v.find(p.back()) != string::npos && v.find(x) != string::npos) {
			//
		} else {
			p += x;
		}
	}
	cout << p << '\n';
}