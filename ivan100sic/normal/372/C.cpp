#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct maxint {
	ll x;
	maxint() : x(-4e18) {}
	maxint(ll x) : x(x) {}
	maxint operator+ (const maxint& b) const {
		return max(x, b.x);
	}
	maxint& operator+= (const maxint& b) {
		x = max(x, b.x);
		return *this;
	}
};

template<class T>
class monotonic_queue {
	basic_string<pair<T, T>> a, b;

	void push(basic_string<pair<T, T>>& a, T x) {
		if (a.size()) {
			a += {x, a.back().second + x};
		} else {
			a += {x, x};
		}
	}

	void rotate() {
		while (a.size()) {
			push(b, a.back().first);
			a.pop_back();
		}
	}

public:
	void push(T x) {
		push(a, x);
	}

	T sum() {
		T x = T();
		if (a.size())
			x += a.back().second;
		if (b.size())
			x += b.back().second;
		return x;
	}

	T top() {
		if (!b.size())
			rotate();
		return b.back().first;
	}

	void pop() {
		if (!b.size())
			rotate();
		b.pop_back();
	}
};

ll n, m, d;
ll dp[150005], nu[150005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> d;
	ll last = 0;
	while (m--) {
		ll a, b, t;
		cin >> a >> b >> t;
		ll h = d*(t-last);
		monotonic_queue<maxint> q;
		for (ll i=1; i<=min(1+h, n); i++) {
			q.push(dp[i]);
		}
		for (ll i=1; i<=n; i++) {
			nu[i] = q.sum().x + b - abs(a - i);
			if (i+h+1 <= n)
				q.push(dp[i+h+1]);
			if (i-h >= 1)
				q.pop();
		}
		copy(nu+1, nu+n+1, dp+1);
		last = t;
	}
	cout << *max_element(dp+1, dp+n+1) << '\n';
}