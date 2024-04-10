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
using namespace std;
#define pb push_back;
#define po(x) 1<<x
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 507
#define DIM2 10007
#define MODULO 1000000007
const ll INF = 10E16;
const ll mask = po(9)-1;
struct pp {
	ll fi, sc;
	bool operator < (const pp b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
ll n,D[DIM][DIM];
char A[DIM];
ll dp(ll l, ll r) {
	if (D[l][r] != -1)return D[l][r];
	if (l > r)return 0;
	if (l == r) {
		D[l][r] = 1;
		return 1;
	}
	
	ll res = dp(l + 1, r) + 1;
	for (ll i = l + 1; i <= r; i++) {
		if (A[i]==A[l])res = min(res, dp(l + 1, i - 1) + dp(i, r));
	}
	D[l][r] = res;
	return res;
}
int main() {
	schnell;
	cin >> n;
	forn(i, n) {
		cin >> A[i];
	}
	forn(i, n) {
		forn(j, n)D[i][j] = -1;
	}
	cout << dp(1, n) << endl;

}