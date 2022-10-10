// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		basic_string<int> v;
		for (int q=0; q<x; q=x/(x/(q+1))) // najjaca linija koda
			v += q;
		v += x;
		cout << v.size() << '\n';
		for (int x : v)
			cout << x << ' ';
		cout << '\n';
	}
}

// I will still practice daily...