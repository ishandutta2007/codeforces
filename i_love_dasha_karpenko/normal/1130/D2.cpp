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
#define DIM 5007
#define DIM2 10007
#define MODULO 998244353 
#define MAXN 10E18
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
struct node {
	ll x, m, num;
};
ll n, m,C[DIM];
ll A[DIM];
int main() {
	schnell;
	cin >> n>>m;
	forn(i, n)A[i] = INF;
	forn(i, m) {
		ll x, y;
		cin >> x >> y;
		ll r = y - x;
		if (r < 0)r += n;
		A[x] = min(A[x], r);
		C[x]++;
	}
	forn(i, n) {
		if (C[i] == 0)A[i] = 0;
	}
	forn(i, n) {
		ll res = 0,r = 1,j = i;
		while(r<=n){
			ll cof = j - i;
			if (cof < 0)cof += n;
			if (C[j]>0)
			res = max(res, A[j] + cof + (C[j]-1) * n);
			j++;
			if (j > n)j = 1;
			r++;
		}
		cout << res << ' ';
	}
	cout << endl;
	return 0;
}