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
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 100007
#define DIM2 10007
#define MODULO 998244353 
#define MAXN 1000000
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
ll n, m ,A[DIM],C[DIM];
priority_queue<pp, vector<pp>, greater<pp> > Q;
int main() {
	schnell;
	cin >> n >> m;
	forn(i, n)cin >> A[i];
	forn(i, n) {
		cin >> C[i];
		Q.push(pp{ C[i],i });
	}
	forn(i, m) {
		ll x, y;
		cin >> x >> y;
		ll res = 0;
		ll cof = min(A[x], y);
		A[x] -= cof;
		y -= cof;
		res += cof * C[x];
		while (!Q.empty() && y > 0) {
			pp u = Q.top();
			while (!Q.empty() && A[u.sc] == 0) {
				Q.pop();
				if (!Q.empty())
				u = Q.top();
			}
			cof = min(A[u.sc], y);
			A[u.sc] -= cof;
			y -= cof;
			res += cof * C[u.sc];
		}
		if (y > 0)cout << 0 << endl;
		else cout << res << endl;
	}
	return 0;
}