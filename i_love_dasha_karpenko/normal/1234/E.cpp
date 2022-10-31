#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
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
bool const operator>(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc > b.sc;
	return a.fi > b.fi;
}
ll n, m, A[DIM],s[DIM];
vector<pp> vec;
priority_queue<pp, vector<pp>, greater<pp> > Q;
int main() {
	schnell;
	cin >> n >> m;
	
	forn(i, m)cin >> A[i];
	ll allsum = 0;
	forn(i, m - 1) {
		allsum += abs(A[i] - A[i + 1]);
		vec.pb({ min(A[i],A[i + 1]),max(A[i],A[i + 1]) });
		ll a = max(A[i], A[i + 1]), b = min(A[i], A[i + 1]);
		if (a == b)continue;
		s[a] += b - a+b;
		s[b] += a - 1-a+b;
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	ll csum = 0;
	for (ll i = 1; i <= n; i++) {
		while (!vec.empty() && vec.back().fi < i) {
			allsum -= vec.back().sc - vec.back().fi;
			csum += vec.back().sc - vec.back().fi - 1;
			Q.push({ vec.back().sc,vec.back().sc - vec.back().fi });
			vec.pop_back();
		}
		while (!Q.empty() && Q.top().fi <= i) {
			allsum += Q.top().sc;
			csum -= Q.top().sc - 1;
			Q.pop();
		}
		cout << allsum + csum + s[i] << ' ';
	}
	return 0;
}