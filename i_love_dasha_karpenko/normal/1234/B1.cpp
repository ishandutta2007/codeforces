#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 300007
const ll MOD = 1000000007;
const ll MAXN = 10E18;
const ll INF = 10E16;
const ll masksz = 1048576;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
deque<ll> deq;
ll n, k;
set<ll> S;
int main() {
	schnell;
	cin >> n >> k;
	forn(i, n) {
		ll x; cin >> x;
		if (S.count(x) == 0) {
			S.insert(x);
			if (deq.size()>=k) {
				S.erase(deq.back());
				deq.pop_back();
			}
			deq.push_front(x);
		}
	}
	cout << deq.size() << endl;
	for (ll to : deq)cout << to << ' ';
	cout << endl;
	return 0;
}