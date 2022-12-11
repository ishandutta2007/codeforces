
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int inf = 1e9;

char lower(char c) {
	if (c >= 'a' && c <= 'z') {
		return c;
	}
	return c - 'A' + 'a';
}

char upper(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c;
	}
	return c - 'a' + 'A';
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	string a, b;
	cin >> a >> b;
	string s;
	cin >> s;

	for (int i = 0; i < sz(s); ++i) {
		char c = lower(s[i]);
		int z = -1;
		for (int j = 0; j < sz(a); ++j) {
			if (a[j] == c) {
				z = j;
			}
		}
		if (z == -1) {
			cout << s[i];
		} else {
			if (c == s[i]) {
				cout << b[z];
			} else {
				cout << upper(b[z]);
			}
		}
	}

	cout << "\n";

}