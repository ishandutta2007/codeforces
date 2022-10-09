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

	int n;
	cin >> n;
	vector<string> a(n);
	for (auto& s : a)
		cin >> s;
	sort(a.begin(), a.end(), [](string u, string v) {
		ll us = count(u.begin(), u.end(), 's');
		ll uh = count(u.begin(), u.end(), 'h');
		ll vs = count(v.begin(), v.end(), 's');
		ll vh = count(v.begin(), v.end(), 'h');
		return us*vh > vs*uh;
	});

	string t;
	for (string s : a)
		t += s;
	int cs = 0;
	ll z = 0;
	for (char c : t)
		if (c == 'h')
			z += cs;
		else
			cs++;
	cout << z << '\n';
}