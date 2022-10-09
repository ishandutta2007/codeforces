#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string bump(string p) {
	p.back()++;
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int d = find(s.begin(), s.end(), '.') - s.begin();
	string p = s.substr(0, d);
	string q = s.substr(d+1);
	if (p.back() == '9')
		cout << "GOTO Vasilisa.\n";
	else if (q < "5")
		cout << p;
	else
		cout << bump(p) << '\n';
}