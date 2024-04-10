
/*
    Im not gonna run away, I never go back on my word! Thats my nindo: my ninja way. Naruto
























































*/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define speed_up ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define szc(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound 
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 1e5 + 2;
const int M = 2e6 + 2;
const int mod = 998244353;
const int inf = 2e9 + 3;
const ll INF = 1e16;

/*
	BIN POISK EBANA V ROT
	DP EBANA V ROT
	DO EBANA V ROT
*/

int n;
ll l[N], r[N], y[N];

struct cht {
	vector <pair <ld, ld>> linesmin, linesmax;
	int posmin = 0, posmax = 0;
	
	ld cross (pair <ld, ld> a, pair <ld, ld> b) {
		return (b.S - a.S) / (a.F - b.F);
	}
	
	void addmin(pair <ld, ld> line) {
		while (sz(linesmin) > 1) {
			int l = sz(linesmin) - 1;
			if (cross(linesmin[l], linesmin[l - 1]) <= cross(line, linesmin[l - 1]))
				break;
			linesmin.ppb();
		}
		linesmin.pb(line);
		
	}
	
	void addmax(pair <ld, ld> line) {
		while (sz(linesmax) > 1) {
			int l = sz(linesmax) - 1;
			if (cross(linesmax[l], linesmax[l - 1]) <= cross(line, linesmax[l - 1]))
				break;
			linesmax.ppb();
		}
		linesmax.pb(line);
	}
	
	ld getmin(ld k) {
		ld ret = INF;
		for (auto it : linesmin)
			ret = min(ret, it.F * k + it.S);
		//~ return ret;
		while (posmin + 1 < sz(linesmin) && cross(linesmin[posmin], linesmin[posmin + 1]) <= k) {
			posmin++;
		}
		return linesmin[posmin].F * k + linesmin[posmin].S;
	}
	
	ld getmax(ld k) {
		ld ret = -INF;
		for (auto it : linesmax)
			ret = max(ret, it.F * k + it.S);
		//~ return ret;		
		while (posmax + 1 < sz(linesmax) && cross(linesmax[posmax], linesmax[posmax + 1]) <= k) {
			posmax++;
		}
		return linesmax[posmax].F * k + linesmax[posmax].S;
	}	
} t;

int main() {
	scanf("%d", &n);
	set <pair <ld, ld>> lol, ans;
	vector <pair <ld, ld>>omg;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld %lld %lld", &l[i], &r[i], &y[i]);
		omg.pb({y[i], r[i]});
		omg.pb({y[i], l[i]});
	}
	sort(all(omg));
	for (int i = 0; i < sz(omg); ++i) {
		if (i + 1 == sz(omg) || omg[i].F != omg[i + 1].F)
			t.addmax(omg[i]);
	}
	reverse(all(omg));
	for (int i = 0; i < sz(omg); ++i) {
		if (i + 1 == sz(omg) || omg[i].F != omg[i + 1].F)
			t.addmin(omg[i]);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			bool f = 0;
			if (y[i] == y[j])
				continue;
			if (y[i] > y[j]) {
				swap(i, j);
				f  = 1;
			}
			ld ap, am;
			ld dy = abs(y[i] - y[j]);
			ap = (r[i] - l[j] + 0.0) / dy;
			am = (l[i] - r[j] + 0.0) / dy;
			lol.insert({am, ap});
			if (f)
				swap(i, j);
		}
	}
	while (sz(lol) >= 2) {
		auto it2 = lol.begin();
		auto it1 = lol.begin();
		it2++;
		if (it1->S > it2->F) {
			pair <ld, ld> cnt = {it1->F, max(it1->S, it2->S)};
			lol.erase(it1);
			lol.erase(it2);
			lol.insert(cnt);
		}
		else {
			ans.insert(*it1);
			lol.erase(it1);
		}
	}
	for (auto it : lol)
		ans.insert(it);
	ld anss = INF;
	set <ld> check;
	for (auto it : ans) {
		check.insert(it.F);
		check.insert(it.S);
		if (it.S <= 0.0 && abs(it.S - 0.0) <= abs(anss - 0.0))
			anss = it.S;
		if (it.F >= 0.0 && abs(it.F - 0.0) <= abs(anss - 0.0))
			anss = it.F;
		if (it.F <= 0.0 && it.S >= 0.0) {
			if (abs(it.F - 0.0) <= abs(anss - 0.0))
				anss = it.F;
			if (abs(it.S - 0.0) <= abs(anss - 0.0))
				anss = it.S;					
		}
	}
	if (sz(ans) == 0)
		check.insert(0.0);	
	ld mn = INF;
	for (auto anss : check) {
		mn = min(mn, t.getmax(anss) - t.getmin(anss));
	}
	cout << fixed << setprecision(6) << mn << '\n';
}

/*
	Timus: 288481RF
	CodeForces: fractal
*/