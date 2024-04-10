#include <iostream>
#include <algorithm>
using namespace std;

int a[200009], r[200009];
long long md = 998244353;

long long fp(long long n, long long k)
{
	long long s = 1;
	while (k) {
		if (k & 1LL) s = (s * n) % md;
		n = (n * n) % md; k /= 2;
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		r[a[i]] = i;
	}
	r[n] = -1;
	for (int i = 0; i < n - 1; i++) 
		if (r[a[i] + 1] < r[a[i + 1] + 1])
			k++;
	if (n > k) cout << 0 << '\n';
	else {
		swap(n, k);
		long long ans = 1, rs = 1;
		for (int i = n; i > n - k; i--)
			ans = (ans * i) % md;
		for (int i = 1; i <= k; i++)
			rs = (rs * i) % md;
		cout << (ans * fp(rs, md - 2)) % md << '\n';
	}
	return 0;
}