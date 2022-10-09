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

	string s;
	cin >> s;

	map<string, int> mp;

	for (int i=0; i<10; i++) {
		string p;
		cin >> p;
		mp[p] = i;
	}
	for (int i=0; i<80; i+=10) {
		cout << mp[s.substr(i, 10)];
	}
	cout << '\n';
}