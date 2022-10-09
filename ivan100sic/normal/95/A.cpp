#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s[105], t;
bool mark[105];
char x;

bool eq(char x, char y) {
	return abs(x - y) % 32 == 0;
}

char adapt(char x, char y) {
	return isupper(x) ? toupper(y) : tolower(y);
}

bool ok(int j, string& s) {
	for (int k=0; k<(int)s.size(); k++) {
		if (j+k >= (int)t.size())
			return false;
		if (!eq(s[k], t[j+k]))
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> s[i];
	cin >> t >> x;
	for (int i=0; i<n; i++)
		for (int j=0; j<(int)t.size(); j++)
			if (ok(j, s[i]))
				fill(mark+j, mark+j+s[i].size(), true);
	for (int i=0; i<(int)t.size(); i++)
		if (mark[i]) {
			if (eq(t[i], x)) {
				if (eq(x, 'a'))
					t[i] = adapt(t[i], 'b');
				else
					t[i] = adapt(t[i], 'a');
			} else
				t[i] = adapt(t[i], x);
		}
	cout << t << '\n';
}