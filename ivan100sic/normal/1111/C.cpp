#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll A, B;

ll solve(basic_string<int> a, int l, int r) {
	if (!a.size())
		return A;
	if (r-l == 1)
		return B * a.size();
	ll v = B * a.size() * (r-l);
	basic_string<int> al, ah;
	int m = (l+r) >> 1;
	for (int x : a)
		if (x < m)
			al += x;
		else
			ah += x;
	return min(v, solve(al, l, m) + solve(ah, m, r));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k >> A >> B;
	basic_string<int> a;
	while (k--) {
		int x;
		cin >> x;
		a += x-1;
	}
	cout << solve(a, 0, 1 << n) << '\n';
}