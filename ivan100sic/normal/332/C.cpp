#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct sumset_hi {
	ll sum;
	int limit;
	multiset<ll> a;

	sumset_hi(int limit) : sum(0), limit(limit) {}

	void insert(ll x) {
		a.insert(x);
		sum += x;
		if ((int)a.size() > limit) {
			auto it = a.begin();
			sum -= *it;
			a.erase(it);
		}
	}

	ll val() const {
		if ((int)a.size() != limit) {
			return -1e18;
		}
		return sum;
	}
};

struct order {
	int a, b, tag;
	bool operator< (const order& o) const {
		if (b != o.b)
			return b > o.b;
		return a < o.a;
	}
};

int n, p, k;
order a[100005];
ll pref[100005], suff[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> p >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i].a >> a[i].b;
		a[i].tag = i;
	}
	sort(a, a+n);

	sumset_hi s1(k), s2(p-k);
	pref[0] = s1.val();
	for (int i=0; i<n; i++) {
		s1.insert(a[i].a);
		pref[i+1] = s1.val();
	}

	suff[n] = s2.val();
	for (int i=n-1; i>=0; i--) {
		s2.insert(a[i].b);
		suff[i] = s2.val();
	}

	pair<ll, ll> sol = {-2e18, -2e18};
	int j = -1;
	for (int i=0; i<=n; i++) {
		// cerr << "info " << pref[i] << ' ' << suff[i] << '\n';
		pair<ll, ll> t = {pref[i], suff[i]};
		if (t.second < 0)
			continue;
		if (t > sol) {
			sol = t;
			j = i;
		}
	}
	// cerr << j << ' ' << sol.first << ' ' << sol.second << '\n';
	// uzmi najboljih k sa pocetka i p-k sa kraja
	vector<int> ans;
	vector<pair<ll, int>> rr;
	for (int i=0; i<j; i++)
		rr.emplace_back(a[i].a, a[i].tag);
	sort(rr.begin(), rr.end(), greater<pair<ll, int>>());
	for (int i=0; i<k; i++)
		ans.push_back(rr[i].second);
	rr.clear();
	for (int i=j; i<n; i++)
		rr.emplace_back(a[i].b, a[i].tag);
	sort(rr.begin(), rr.end(), greater<pair<ll, int>>());
	for (int i=0; i<p-k; i++)
		ans.push_back(rr[i].second);
	for (int x : ans)
		cout << x+1 << ' ';
	cout << '\n';
}