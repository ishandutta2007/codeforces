#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
	string s;
	cin >> s;
	s += ",";
	string w, a, b;
	bool is_number = true;
	for (char c : s) {
		if (c == ',' || c == ';') {
			if (w != "") {
				if (w[0] == '0' && w.length() > 1) is_number = false;
			} else is_number = false;
			if (is_number) a = a + w + ",";
			else b = b + w + ",";
			is_number = true;
			w = "";
		} else {
			w += c;
			if (c < '0' || c > '9') is_number = false;
		}
	}
	if (a == "") cout << "-\n";
	else {
		cout << '"';
		for (int i = 0; i < a.size() - 1; ++i) cout << a[i];
		cout << "\"\n";
	}
	if (b == "") cout << "-\n";
	else {
		cout << "\"";
		for (int i = 0; i < b.size() - 1; ++i) cout << b[i];
		cout << "\"\n";
	}
}