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
	string s;
	cin >> n >> s;

	if (s.size() == 1)
		return cout << (s[0] == '0' ? "No\n" : "Yes\n"), 0;

	for (int i=0; i<n-1; i++)
		if (s[i] == '1' && s[i+1] == '1')
			return cout << "No\n", 0;

	for (int i=0; i<n-2; i++)
		if (s[i] == '0' && s[i+1] == '0' && s[i+2] == '0')
			return cout << "No\n", 0;

	if (s.substr(0, 2) == "00")
		return cout << "No\n", 0;

	if (s.substr(n-2, 2) == "00")
		return cout << "No\n", 0;

	cout << "Yes\n";
}