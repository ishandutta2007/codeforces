#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long md = 1000000007;

long long fp(long long n, long long k)
{
	long long s = 1;
	while (k) {
		if (k & 1) s = (s * n) % md;
		n = (n * n) % md; k /= 2;
	}
	return s;
}

long long ft[3000009], rf[3000009];

long long cb(long long n, long long k)
{
	if (n < k) return 0LL;
	return (((ft[n] * rf[k]) % md) * rf[n - k]) % md;
}

vector<long long> prd(vector<long long> a, vector<long long> b) {
	vector<long long> q;
	long long br = fp(b[0], md - 2);
	for (int i = 0; i + b.size() <= a.size(); i++) {
		q.push_back((a[i] * br) % md);
		for (int j = 0; j < b.size(); j++) a[i + j] = (a[i + j] - ((q[i] * b[j]) % md) + md) % md;
	}
	return q;
}

vector<long long> v, tv, rv, r;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q; cin >> n >> q;
	ft[0] = rf[0] = 1;
	for (int i = 1; i <= 3 * n + 3; i++)
		ft[i] = (ft[i - 1] * i) % md;
	rf[3 * n + 3] = fp(ft[3 * n + 3], md - 2);
	for (int i = 3 * n + 2; i >= 1; i--)
		rf[i] = (rf[i + 1] * (i + 1)) % md;
	for (int i = 0; i <= 3 * n; i++) {
		v.push_back(cb(3 * n + 1, i + 1));
		tv.push_back(v.back());
	}

	tv.push_back(0LL);
	for (int i = 0; i <= 3 * n; i++)
		tv[i + 1] += v[i];
	v.push_back(0);
	for (int i = 0; i <= 3 * n + 1; i++)
		v[i] = tv[i];
	v.push_back(0);
	for (int i = 0; i <= 3 * n + 1; i++)
		v[i + 1] += tv[i];
	for (int i = 0; i <= 3 * n + 2; i++)
		v[i] %= md;

	rv.push_back(3);
	rv.push_back(3);
	rv.push_back(1);
	reverse(v.begin(), v.end());
	reverse(rv.begin(), rv.end());
	r = prd(v, rv);
	reverse(r.begin(), r.end());

	for (int i = 0; i < q; i++) {
		int t; cin >> t;
		cout << r[t] << '\n';
	}
	return 0;
}