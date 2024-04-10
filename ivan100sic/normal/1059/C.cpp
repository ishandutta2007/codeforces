#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> niz(int n, int f) {
	if (n == 1)
		return {f};
	if (n == 2)
		return {f, 2*f};
	if (n == 3)
		return {f, f, 3*f};

	vector<int> r((n+1)/2, f);
	auto rr = niz(n - (n+1)/2, 2*f);
	copy(rr.begin(), rr.end(), back_inserter(r));
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	auto r = niz(n, 1);
	for (int x : r)
		cout << x << ' ';
	cout << '\n';
}