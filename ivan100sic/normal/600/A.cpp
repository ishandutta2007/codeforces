// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void pr(vector<string> a) {
	if (a.size() == 0) {
		cout << "-\n";
	} else {
		cout << "\"";
		cout << a[0];
		for (int i=1; i<(int)a.size(); i++) {
			cout << ',' << a[i];
		}
		cout << "\"\n";
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s;
	vector<string> a, b;
	cin >> s;
	string t;

	auto ad = [&]() {
		bool ok = isdigit(t[0]) && t[0] != '0';
		for (char x : t) {
			if (!isdigit(x)) {
				ok = 0;
			}
		}
		if (t == "0")
			ok = 1;
		(ok ? a : b).push_back(t);
		t = "";
	};

	for (char x : s) {
		if (x == ';' || x == ',') {
			ad();
		} else {
			t += x;
		}
	}

	ad();

	pr(a);
	pr(b);
}