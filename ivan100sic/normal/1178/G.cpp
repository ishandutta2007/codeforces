#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct line {
	ll k, b, poc;

	bool operator< (const line& other) const {
		return tie(k, b) < tie(other.k, other.b);
	}

	bool iznad(const line& other) const {
		return other.poc*other.k+other.b <= other.poc*k+b;
	}

	ll presek(const line& other) const {
		ll p = other.b - b;
		ll q = k - other.k;
		return p<0 ? p/q : (p+q-1)/q;
	}
};

struct convexhull {
	vector<line> a;
	int p;

	void dodaj(ll k, ll b) {
		a.push_back({k, b, -3000000000ll});
	}

	void zavrsi() {
		sort(a.begin(), a.end());
		vector<line> b;
		for (line c : a) {
			while (b.size() >= 1 && c.iznad(b.back()))
				b.pop_back();
			if (b.size())
				c.poc = c.presek(b.back());
			b.push_back(c);
		}
		swap(a, b);
		p = 0;
	}

	ll resi(ll x) {
		while (p+1 < (int)a.size() && a[p+1].poc <= x)
			p++;
		return a[p].k*x + a[p].b;
	}
};

struct upit {
	int t, v, x;
} u[100005];

int n, q;
basic_string<int> e[200005];
int a[200005], b[200005];

int sa[200005], sb[200005];
int el[200005], er[200005], t;

void dfs(int x, int p) {
	el[x] = t;
	sa[t] = sa[el[p]] + a[x];
	sb[t] = sb[el[p]] + b[x];
	t++;
	for (int y : e[x])
		dfs(y, x);
	er[x] = t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=2; i<=n; i++) {
		int p;
		cin >> p;
		e[p] += i;
	}

	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> b[i];

	for (int i=0; i<q; i++) {
		cin >> u[i].t >> u[i].v;
		if (u[i].t == 1)
			cin >> u[i].x;
	}

	dfs(1, 0);

	for (int i=1; i<=n; i++)
		sb[i] = abs(sb[i]);

	for (int ul=0, ur=2000; ul<q; ul+=2000, ur+=2000) {
		ur = min(ur, q);
		basic_string<int> cm;

		for (int j=ul; j<ur; j++) {
			cm += el[u[j].v];
			cm += er[u[j].v];
		}

		sort(cm.begin(), cm.end());
		cm.erase(unique(cm.begin(), cm.end()), cm.end());
		int b = cm.size() - 1;

		vector<convexhull> ha(b), hb(b);
		vector<int> d(b);

		for (int i=0; i<b; i++) {
			for (int j=cm[i]; j<cm[i+1]; j++) {
				ha[i].dodaj( sb[j],  1ll*sa[j]*sb[j]);
				hb[i].dodaj(-sb[j], -1ll*sa[j]*sb[j]);
			}
			ha[i].zavrsi();
			hb[i].zavrsi();
		}

		for (int j=ul; j<ur; j++) {

			int wl = lower_bound(cm.begin(), cm.end(), el[u[j].v]) - cm.begin();
			int wr = lower_bound(cm.begin(), cm.end(), er[u[j].v]) - cm.begin();

			if (u[j].t == 1) {
				for (int k=wl; k<wr; k++)
					d[k] += u[j].x;
			} else {
				ll ans = 0;
				for (int k=wl; k<wr; k++) {
					ans = max(ans, ha[k].resi(d[k]));
					ans = max(ans, hb[k].resi(d[k]));
				}
				cout << ans << '\n';
			}
		}

		for (int i=0; i<b; i++) {
			for (int j=cm[i]; j<cm[i+1]; j++) {
				sa[j] += d[i];
			}
		}
	}
}