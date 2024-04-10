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
	int x = count(s.begin(), s.end(), 'a');
	int n = s.size();
	while (2*x <= n) {
		n--;
	}
	cout << n << '\n';
}