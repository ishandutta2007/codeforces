#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
using namespace std;
#define pb push_back
#define po(x) 1<<x
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 200007
#define DIM2 10007
#define MODULO 1000000007
#define MAXN 10E9
const ll INF = 10E16;
const ll mask = po(9) - 1;
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

ll n, m, k;
pp A[DIM];
vector<ll> ans;

int main() {
	schnell;
	cin >> n >> m >> k;
	forn(i, n) {
		cin >> A[i].fi;
		A[i].sc = i;
	}
	sort(A + 1, A + 1 + n);
	ll res = 0;
	for (ll i = n; i > n-m*k; i--) {
		res += A[i].fi;
		ans.pb(A[i].sc);

	}
	sort(ans.begin(), ans.end());
	cout << res << endl;
	ll cn = 1;
	for (ll i = m - 1; i < ans.size() && cn<k; i += m) {
		if (ans[i]<=n-m)
		cout << ans[i] << ' ';
		cn++;
	}
	return 0;
}