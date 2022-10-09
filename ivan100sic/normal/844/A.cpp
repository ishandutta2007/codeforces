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

	string s;
	cin >> s;
	int n;
	cin >> n;
	if (n > (int)s.size())
		cout << "impossible\n";
	else {
		cout << max(0, n - (int)set<char>(s.begin(), s.end()).size()) << '\n';
	}
}