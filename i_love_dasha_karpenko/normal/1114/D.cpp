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
typedef long ll;
typedef long double ld;
#define DIM 5007
#define DIM2 10007
#define MODULO 1000000007
#define MAXN 10E18
const ll INF = po(30);
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
ll n, A[DIM],D[2][DIM][DIM];
ll dp(ll l, ll r,ll last) {
	if (l > r || l<1 || r>n)return INF;
	if (D[last][l][r] != -1)return D[last][l][r];
	if (l == 1 && r == n)return 0;
	ll e = INF;
	if ((last == 0 && A[l - 1] == A[l]) || (last == 1 && A[l - 1] == A[r])) {
		e = min(e, dp(l - 1, r, 0));
	}
	else {
		e = min(e, dp(l - 1, r, 0) + 1);
	}
	if ((last == 0 && A[r + 1] == A[l]) || (last == 1 && A[r + 1] == A[r])) {
		e = min(e, dp(l, r + 1, 1));
	}
	else {
		e = min(e, dp(l, r + 1, 1) + 1);
	}
	D[last][l][r] = e;
	return e;
}
int main() {
	//schnell;
	srand(time(NULL));
	cin >> n;
	forn(i, n) {
		cin >> A[i];
	}
	memset(D, -1, sizeof(D));
	ll res = INF;
	for (ll i = 1; i <= n; i++) {
		res = min(res, dp(i, i,0));
	}
	cout << res << endl;
}