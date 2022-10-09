#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	valarray<long long> p(n), q(n);
	for (int i=1; i<n; i++)
		cin >> p[i];
	partial_sum(begin(p), end(p), begin(q));
	q -= *min_element(begin(q), end(q)) - 1;
	fill(begin(p), end(p), 0);
	for (auto x : q)
		if (x < 1 || x > n || p[x-1]++)
			return cout << -1, 0;
	copy(begin(q), end(q), ostream_iterator<int>(cout, " "));
}