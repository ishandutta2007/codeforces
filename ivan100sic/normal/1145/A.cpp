#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int thanos(basic_string<int> a) {
	int n = a.size();
	if (is_sorted(a.begin(), a.end()))
		return n;
	return max(thanos(a.substr(0, n/2)), thanos(a.substr(n/2)));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	basic_string<int> a;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a += x;
	}

	cout << thanos(a) << '\n';
}