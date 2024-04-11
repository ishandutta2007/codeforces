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

map<string, int> asd;

set<pair<int, string> > qwe;

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
	forn(i, n){
		string str;
		cin >> str;
		qwe.erase(mk(asd[str], str));
		qwe.insert(mk(-i, str));
		asd[str] = -i;
	}
	for (auto ind = qwe.begin(); ind != qwe.end(); ind ++)
		cout << (*ind).Y << endl;
	return 0;
}