#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool subseq(string a, string b) {
	int j = 0;
	for (char x : b) {
		if (x == a[j])
			j++;
		if (j == (int)a.size())
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;

	for (int i=0; i<1000; i+=8) {
		string p = to_string(i);
		if (subseq(p, s)) {
			cout << "YES\n" << p << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}