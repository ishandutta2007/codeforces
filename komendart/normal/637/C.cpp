#define filesfl 0
#define consolefl 01
#define fname "sufpref"
//evgenstf - batya

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <stdint.h>

#include <cmath>
#include <algorithm>

#include <set>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <bitset>

#define forn(i, n) for (ll i = 0; i < n; ++ i)
#define fornn(i, q, n) for (ll i = q; i < n; ++ i)
#define rforn(i, n) for (ll i = n; i >= 0; i --)
#define rfornn(i, m, n) for (ll i = m; i >= n; i --)

#define endl "\n"
#define inb push_back
#define outb pop_back
#define X first
#define Y second
#define Z third
#define mk make_pair
#define _i "%d"
#define _ll "%I64d"
#define pii pair<ll, ll>
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define all(v) v.begin(), v.end()

#define nsc(n) scanf("%d", &n)
#define nmsc(n, m) scanf("%d%d", &n, &m)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const ll inf = 1e9 + 5;
const ll linf = 5e18 + 5;
const ld eps = 1e-9;

const ll dd = 1e6 + 7;
const ll maxn = 2e3 + 10;

const ll mod = 1e9 + 7;

using namespace std;

string a[1005];

vector<char> qwe;

string now;


bool fun(string a, string b, int k, int ind){
	if (ind == a.size()){
		int cnta = 0;
		forn(i, a.size())
			if (a[i] != now[i])
				cnta ++;
		int cntb = 0;
		forn(i, b.size())
			if (b[i] != now[i])
				cntb ++;
		if (cnta <= k && cntb <= k)
			return 0;
		return 1;
	}
	bool fl = 1;
	now.inb(a[ind]);
	fl = fun(a, b, k, ind + 1);
	now.outb();
	if (!fl)
		return fl;
	now.inb(b[ind]);
	fl = fun(a, b, k, ind + 1);
	now.outb();
	if (!fl)
		return fl;
	if (a[ind] != '0' && b[ind] != '0')
		now.inb('0');
	else
		if (a[ind] != '1' && b[ind] != '1')
			now.inb('1');
		else
			if (a[ind] != '2' && b[ind] != '2')
				now.inb('2');
	fl = fun(a, b, k, ind + 1);
	now.outb();
	return fl;
}


int main() {
	ios_base::sync_with_stdio(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	if (filesfl) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else {
		if (!consolefl) {
			freopen(fname".in", "r", stdin);
			freopen(fname".out", "w", stdout);
		}
	}
#endif
	int n;
	cin >> n;
	forn(i, n)
		cin >> a[i];
	if (n == 1){
		cout << 6;
		exit(0);
	}
	int ans = 6;
	forn(i, n)
		fornn(j, i + 1, n){
			int cnt = 0;
			forn(q, a[i].size())
				if (a[i][q] != a[j][q])
					cnt ++;
			if (cnt < 3)
				ans = min(ans, 0);
			if (3 <= cnt && cnt < 5)
				ans = min(ans, 1);
			if (5 <= cnt)
				ans = min(ans, 2);
		}
	cout << ans;
	return 0;
}