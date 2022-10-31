#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
const ll BLOCK = 400;
const ll DIM = 2007;
const ll MOD = 1000000007;
const ll MAXN = 10E18;
const ll INF = 10E16;
const ll masksz = po(20);
const ll bufsize = 500;
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
struct node {
	ll x, y, z;
};
ll n,vis[DIM];
node A[DIM];
ll di(node a, node b) {
	return abs(a.x - b.x) + abs(a.y - b.y) + abs(b.z - a.z);
}
int main() {
	schnell;
	cin >> n;
	forn(i, n) {
		cin >> A[i].x >> A[i].y >> A[i].z;
	}
	forn(i, n) {
		if (vis[i])continue;
		ll dot; ll dist = INF;
		forn(j, n) {
			if (i != j && vis[j] == 0) {
				if (di(A[i], A[j]) < dist) {
					dist = di(A[i], A[j]);
					dot = j;
				}
			}
		}
		cout << i << ' ' << dot << endl;
		vis[i] = 1;
		vis[dot] = 1;
	}
	return 0;
}