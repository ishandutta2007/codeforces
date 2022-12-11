#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

class fenwick
{
public:
	fenwick(int n) : n(n)
	{
		f.resize(n);
		sum = 0;
	}

	void update(int pos, ll val)
	{
		sum += val;
		for (; pos < n; pos = (pos | (pos + 1))) {
			f[pos] += val;
		}
	}

	ll get(int pos)
	{
		ll ans = 0;
		for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
			ans += f[pos];
		}
		return ans;
	}

	ll getSum() const
	{
		return sum;
	}
private:
	int n;
	vector<ll> f;
	ll sum;
};

int main()
{

	//ifstream cin("input.txt");

	//freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);

	vector<int> p(n);
	ll start = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		--p[i];
	}

	fenwick f1(n);
	for (int i = 0; i < n; ++i) {
		start += f1.getSum() - f1.get(p[i]);
		f1.update(p[i], 1);
	}

	ld ans = ld(start);
	ld den = ld(n) * ld(n + 1) / 2;
	for (int k = 1; k <= n; ++k) {
		ld val = ld(k) * ld(k - 1) / 4;
		ans += ld(n - k + 1) * val / den;
	}

	fenwick f2(n);
	ld prev = 0;

	for (int i = n - 1; i >= 0; --i) {
		prev += f2.get(p[i]);
		f2.update(p[i], n - i);
		ans -= ld(prev) / den;
	}

	cout << fixed;
	cout.precision(12);
	cout << ans << "\n";

}