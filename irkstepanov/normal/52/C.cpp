#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

struct node {
	ll promise;
	ll minn;
	node() : promise(0), minn(0) {}
};

vector<node> t;

void push(int v) {
	ll x = t[v].promise;
	t[v * 2].promise += x;
	t[v * 2].minn += x;
	t[v * 2 + 1].promise += x;
	t[v * 2 + 1].minn += x;
	t[v].promise = 0;
}

void upd(int v, int tl, int tr, int l, int r, ll val) {
	if (tl == l && tr == r) {
		t[v].promise += val;
		t[v].minn += val;
		return;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	if (l <= tm) {
		upd(v * 2, tl, tm, l, min(r, tm), val);
	}
	if (r > tm) {
		upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
	}
	t[v].minn = min(t[v * 2].minn, t[v * 2 + 1].minn);
}

ll get(int v, int tl, int tr, int l, int r) {
	if (tl == l && tr == r) {
		return t[v].minn;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	ll ans = 1e18;
	if (l <= tm) {
		ans = min(ans, get(v * 2, tl, tm, l, min(r, tm)));
	}
	if (r > tm) {
		ans = min(ans, get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
	}
	return ans;
}

void parse(const string& s, vector<ll>& vct) {
	int pos = 0;
	int sgn = 1;
	ll val = 0;
	while (pos < sz(s)) {
		if (s[pos] == '-') {
			sgn = -1;
			++pos;
			continue;
		}
		if (isdigit(s[pos])) {
			val *= 10;
			val += s[pos] - '0';
		} else {
			vct.pb(val * sgn);
			val = 0;
			sgn = 1;
		}
		++pos;
	}
	vct.pb(val * sgn);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    t.resize(4 * n);

   	for (int i = 0; i < n; ++i) {
   		ll x;
   		cin >> x;
   		upd(1, 0, n - 1, i, i, x);
   	}

   	int q;
   	cin >> q;

   	string s;
   	getline(cin, s);

   	while (q--) {
   		getline(cin, s);
   		vector<ll> vct;
   		parse(s, vct);
   		int lf = vct[0], rg = vct[1];
   		if (sz(vct) == 2) {
   			if (lf <= rg) {
   				cout << get(1, 0, n - 1, lf, rg) << "\n";
   			} else {
   				cout << min(get(1, 0, n - 1, lf, n - 1), get(1, 0, n - 1, 0, rg)) << "\n";
   			}
   		} else {
   			ll val = vct[2];
   			if (lf <= rg) {
   				upd(1, 0, n - 1, lf, rg, val);
   			} else {
   				upd(1, 0, n - 1, lf, n - 1, val);
   				upd(1, 0, n - 1, 0, rg, val);
   			}
   		}
   	}

}