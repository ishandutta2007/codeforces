// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;
	vector<string> a(n);
	for (auto& s : a)
		cin >> s;
	sort(begin(a), end(a), [&](auto a, auto b) { return a+b < b+a; });
	for (auto s : a)
		cout << s;
	cout << '\n';
}