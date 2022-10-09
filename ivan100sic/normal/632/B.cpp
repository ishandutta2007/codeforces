// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[500005];
string s;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cin >> s;

	ll sa=0, sb=0;
	for (int i=0; i<n; i++)
		if (s[i] == 'A')
			sa += a[i];
		else
			sb += a[i];

	ll delta = 0;
	// prefiks
	ll curr = 0;
	for (int i=0; i<n; i++) {
		if (s[i] == 'A')
			curr += a[i];
		else
			curr -= a[i];
		delta = max(delta, curr);
	}

	// sufiks
	reverse(a, a+n);
	reverse(begin(s), end(s));
	curr = 0;
	for (int i=0; i<n; i++) {
		if (s[i] == 'A')
			curr += a[i];
		else
			curr -= a[i];
		delta = max(delta, curr);
	}

	cout << sb + delta << '\n';
}