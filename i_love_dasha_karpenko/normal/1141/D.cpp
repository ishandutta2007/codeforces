#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 107
#define DIM2 10007
#define MODULO 10000000000 
#define MAXN 1000000
#define DIM2 31
const long long INF = 10E16;
const ll mask = po(9) - 1;
const ll base = 100000000000;
struct pp {
	ll fi, sc;
	bool operator < (const pp& b)const {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp& b)const {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp& b)const {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
ll n;
vector<ll> lx, rx;
vector<ll> L[DIM], R[DIM];
queue<pp> ans;
int main() {
	schnell;
	cin >> n;
	forn(i, n) {
		char x; cin >> x;
		if (x == '?')lx.pb(i);
		else L[x - 'a'+1].pb(i);
	}
	forn(i, n) {
		char x;
		cin >> x;
		if (x == '?')rx.pb(i);
		else R[x - 'a' + 1].pb(i);
	}
	for (ll i = 1; i <= 'z' - 'a' + 1; i++) {
		while (!L[i].empty() && !R[i].empty()) {
			ans.push({ L[i].back(),R[i].back() });
			L[i].pop_back(); R[i].pop_back();
		}
		while (!L[i].empty() && !rx.empty()) {
			ans.push({ L[i].back(),rx.back() });
			L[i].pop_back(); rx.pop_back();
		}
		while (!R[i].empty() && !lx.empty()) {
			ans.push({ lx.back(),R[i].back() });
			lx.pop_back(); R[i].pop_back();
		}
	}
	while (!lx.empty() && !rx.empty()) {
		ans.push({ lx.back(),rx.back() });
		lx.pop_back(); rx.pop_back();
	}
	cout << ans.size() << endl;
	while (!ans.empty()) {
		cout << ans.front().fi << ' ' << ans.front().sc << endl;
		ans.pop();
	}
	return 0;
}