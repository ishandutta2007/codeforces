#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void no() {
	cout << "NO\n";
	exit(0);
}

bool ew(string a, string b) {
	return a.size() >= b.size() && a.substr(a.size() - b.size()) == b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	vector<string> a;
	string s;
	while (cin >> s) {
		a.push_back(s);
	}

	if (a.size() == 1) {
		string s = a[0];
		if (ew(s, "lios") || ew(s, "liala") || ew(s, "etr") ||
			ew(s, "etra") || ew(s, "initis") || ew(s, "inites"))
		{
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	} else {
		int j = -1, c = 0;
		char g = 0;
		for (int i=0; i<(int)a.size(); i++) {
			string s = a[i];
			if (ew(s, "etr")) {
				g = 'm';
				j = i;
				c++;
			} else if (ew(s, "etra")) {
				g = 'f';
				j = i;
				c++;
			}
		}

		if (c != 1)
			no();

		if (g == 'm') {
			for (int i=0; i<j; i++)
				if (!ew(a[i], "lios"))
					no();
			for (int i=j+1; i<(int)a.size(); i++)
				if (!ew(a[i], "initis"))
					no();
		} else {
			for (int i=0; i<j; i++)
				if (!ew(a[i], "liala"))
					no();
			for (int i=j+1; i<(int)a.size(); i++)
				if (!ew(a[i], "inites"))
					no();
		}

		cout << "YES\n";
	}
}