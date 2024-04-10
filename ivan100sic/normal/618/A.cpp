#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		a += 1;
		while (a.size() >= 2 && a[a.size() - 1] == a[a.size() - 2]) {
			int x = a.back();
			a.pop_back();
			a.pop_back();
			a += x+1;
		}
	}
	for (int x : a)
		cout << x << ' ';
	cout << '\n';
}