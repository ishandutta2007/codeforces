//#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <list>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = 200 * 1000 + 13;

int n, m, x;
int lf[N], rg[N];
vector <pt> v;
int t[4 * N];

const int mod = 1000 * 1000 * 1000 + 7;

int sum (int idx, int lf, int rg, int l, int r)
{
	if (lf == l && rg == r)
		return t[idx];
		
	int res = 0;
	
	int mid = (lf + rg) >> 1;
	
	if (l <= mid)
		res += sum(2 * idx + 1, lf, mid, l, min(mid, r));
		
	if (r > mid)
		res += sum(2 * idx + 2, mid + 1, rg, max(l, mid + 1), r);
		
	if (res >= mod)
		res -= mod;
		
	return res;
} 

void upd (int idx, int lf, int rg, int pos, int val)
{
	if (lf == rg)
	{
		t[idx] += val;
		if (t[idx] >= mod)
			t[idx] -= mod;
		return;
	}
	
	int mid = (lf + rg) >> 1;
	
	if (pos <= mid)
		upd(2 * idx + 1, lf, mid, pos, val);
	else
		upd(2 * idx + 2, mid + 1, rg, pos, val);
		
	t[idx] = t[2 * idx + 1] + t[2 * idx + 2];
	
	if (t[idx] >= mod)
		t[idx] -= mod;
}

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	
	cin >> x >> m;
	
	forn(i, m)
	{
		scanf("%d%d", &lf[i], &rg[i]);
		v.pb(mp(rg[i], i));
	}
	
	v.pb(mp(0, -1));
	
	sort(all(v));
	
	n = sz(v);
	
	upd(0, 0, n - 1, 0, 1);
	
	int ans = 0;
	
	/*
	forn(i, sz(v))
		cerr << v[i].ft << ' ' << v[i].sc << endl;
	*/
	
	for1(i, n - 1)
	{
		int curlf = lf[v[i].sc];

		int idxlf = int(lower_bound(all(v), mp(curlf, -1)) - v.begin());
		int idxrg = int(lower_bound(all(v), mp(v[i].ft, -1)) - v.begin()) - 1;
		
		//cerr << i << ' ' << idxlf << ' ' << idxrg << ' ';
		
		if (idxlf > idxrg)
			continue;
			
		int curv = sum(0, 0, n - 1, idxlf, idxrg);
		
		//cerr << curv << endl;
		
		upd(0, 0, n - 1, i, curv);
		
		if (curlf <= x && x <= v[i].ft)
			ans = (ans + curv) % mod;
	}
	
	cout << ans << endl;

	return 0;
}