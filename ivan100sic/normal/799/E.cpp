#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k;
int c[200005], a[200005], b[200005], ab[200005], no[200005];

vector<int> ac, bc, abc, noc;
vector<ll> q, r, s;

multiset<int> resto_l, resto_r;
ll suma_l;

vector<ll> prefix_sum(vector<int>& a) {
	vector<ll> b(a.size() + 1);
	b[0] = 0;
	for (size_t i=0; i<a.size(); i++) {
		b[i+1] = b[i] + a[i];
	}
	return b;
}

void prebaci(size_t target) {
	while (resto_l.size() < target) {
		ll x = *resto_r.begin();
		resto_l.insert(x);
		resto_r.erase(resto_r.begin());
		suma_l += x;
	}

	while (resto_l.size() > target) {
		auto it = --resto_l.end();
		ll x = *it;
		resto_r.insert(x);
		resto_l.erase(it);
		suma_l -= x;
	}
}

void dodaj(int val) {

	if (resto_r.size()) {
		if (val >= *resto_r.begin()) {
			resto_r.insert(val);
		} else {
			resto_l.insert(val);
			suma_l += val;
		}
	} else if (resto_l.size()) {
		if (val > *resto_l.rbegin()) {
			resto_r.insert(val);
		} else {
			resto_l.insert(val);
			suma_l += val;
		}
	} else {
		resto_r.insert(val);
	}		
}

ll sol = 123'123'123'123'123'123ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		cin >> c[i];
	}

	{
		int q;
		cin >> q;
		while (q--) {
			int x;
			cin >> x;
			a[x] = 1;
		}
	}

	{
		int q;
		cin >> q;
		while (q--) {
			int x;
			cin >> x;
			b[x] = 1;
		}
	}

	for (int i=1; i<=n; i++) {
		if (a[i] && !b[i]) {
			ac.push_back(c[i]);
		} else if (b[i] && !a[i]) {
			bc.push_back(c[i]);
		} else if (a[i] && b[i]) {
			abc.push_back(c[i]);
		} else {
			noc.push_back(c[i]);
		}
	}

	sort(ac.begin(), ac.end());
	sort(bc.begin(), bc.end());
	sort(abc.begin(), abc.end());
	// sort(noc.begin(), noc.end());

	q = prefix_sum(ac);
	r = prefix_sum(bc);
	s = prefix_sum(abc);

	cerr << "Sizes: " << ac.size() << ' ' << bc.size() << ' '
		<< abc.size() << ' ' << noc.size() << '\n';

	for (int x : noc) {
		dodaj(x);
	}

	// sve posle k dodaj
	for (int i=k+1; i<(int)ac.size(); i++) {
		dodaj(ac[i]);
	}

	for (int i=k+1; i<(int)bc.size(); i++) {
		dodaj(bc[i]);
	}

	for (int s0=0; s0<=m; s0++) {
		int uz = k - s0;

		if (s0 > (int)abc.size()) {
			break;
		}

		if (uz >= 0 && uz < (int)ac.size()) {
			dodaj(ac[uz]);
		}

		if (uz >= 0 && uz < (int)bc.size()) {
			dodaj(bc[uz]);
		}

		if (uz > (int)ac.size() || uz > (int)bc.size()) {
			continue;
		}		

		ll val = s[s0];
		if (uz >= 0) {
			val += q[uz] + r[uz];
		}

		// cerr << "val: " << val << '\n';
		int proiz = m - s0 - 2*uz;

		if (uz < 0) {
			proiz = m - s0;
		}

		// uzmi ostalo
		if (proiz >= 0 && proiz <= (int)(resto_l.size() + resto_r.size())) {
			prebaci(proiz);
			sol = min(sol, val + suma_l);
		} else {
			//
		}
	}

	if (sol == 123'123'123'123'123'123ll) {
		sol = -1;
	}

	cout << sol;

}