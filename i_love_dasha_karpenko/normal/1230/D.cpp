#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 7007
#define MODULO 998244353 
const ll MAXN = ll(10E8);
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
ll n, A[DIM], B[DIM], dummy, vis[DIM];
map<ll, ll> M, M1;
set<ll> S;
vector<ll> V;
void setbits(ll mask) {
	dummy |= mask;
}
int main() {
	schnell;
	cin >> n;
	forn(i, n) {
		cin >> A[i];
	}
	forn(i, n)cin >> B[i];
	forn(i, n) {
		M[A[i]] += B[i];
		M1[A[i]]++;
		if (M1[A[i]] == 1)V.pb(A[i]);
	}
	ll res = 0;
	sort(V.begin(), V.end());
	for (ll i = V.size()-1; i >= 0; i--) {
		if (vis[i] == 1 || M1[V[i]] == 1)continue;
		for (ll j = i; j >= 0; j--) {
			if (vis[j] == 1 || (V[i] | V[j]) != V[i])continue;
			res += M[V[j]];
			vis[j] = 1;
		}
	}
	//if (M1.count(0) > 1 && S.count(0) == 0)res += M[0];
	cout << res << endl;
	return 0;
}
//110