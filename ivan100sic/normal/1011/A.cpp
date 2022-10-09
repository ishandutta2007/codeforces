#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[26], n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	string s;
	cin >> s;
	for (char x : s)
		c[x-'a']++;

	int z = 0;

	for (int i=0; i<26; i++) {
		if (k && c[i]) {
			z += i+1;
			k--;
			i++;
		}
	}

	if (k)
		z = -1;

	cout << z;
}