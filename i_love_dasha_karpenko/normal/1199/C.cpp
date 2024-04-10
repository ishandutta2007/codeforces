#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long  ll;
typedef long double ld;
#define DIM 400007
#define DIM2 10007
#define MODULO 998244353 
#define MAXN 1000000
#define DIM2 31
const long long INF = 10E16;
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
struct node {
	ll l, r, end, val;
	bool operator < (const node& b)const {
		return val < b.val;
	}
	bool operator > (const node& b)const {
		return val > b.val;
	}
};
bool mc(node a, node b) {
	return a.l < b.l;
}
ll n, I, A[DIM], pref[DIM], pref1[DIM];
ll F(ll x) {
	ll cof = log2(x);
	if (po(cof) < x)cof++;
	return cof;
}
int main() {
	schnell;
	cin >> n >> I;
	I *= 8;
	forn(i, n) {
		cin >> A[i];
	}
	sort(A + 1, A + 1 + n);
	ll ro = 0, res = 0;
	pref[0] = 1;
	pref1[0] = n + 1;
	forn(i, n) {
		while (i < n && A[i] == A[i + 1])i++;

		ro++; res++;

		pref[ro] = i;
	}
	ro = 0;
	for (ll i = n; i >= 1; i--) {
		while (A[i] == A[i - 1] && i > 1)i--;
		ro++;
		pref1[ro] = i;
	}
	ll dif = I / n;
	//dif = F(res) - dif;
	if (log2(res) < dif) {
		cout << 0 << endl;
		return 0;
	}
	if (res <= po(dif)) {
		cout << 0 << endl;
		return 0;
	}
	dif = res - po(dif);

	ll ans = INF;
	for (ll i = dif; i >= 0; i--) {
		if (i == dif) {
			ans = min(ans, pref[i]);
		}
		else if (i == 0) {
			ans = min(n - pref1[dif] + 1, ans);
		}
		else {
			ans = min(ans, pref[i] + n - pref1[dif - i] + 1);
		}
	}
	cout << ans << endl;
	return 0;
}