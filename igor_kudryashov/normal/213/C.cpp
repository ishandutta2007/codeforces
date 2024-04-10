#pragma comment(linker, "/stack:64000000")
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
#include <list>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
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

const int N = 300 + 13;

int n;
int a[N][N];
int d[N][N][N][2];

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	
	cin >> n;
	
	forn(i, n)
		forn(j, n)
			scanf("%d", &a[i][j]);
			
	forn(i, n)
		forn(j, n)
			forn(k, n)
				forn(it, 2)
					d[i][j][k][it] = -INF;
				
	d[0][0][0][0] = a[0][0];
	
	forn(i, n)
	{
		forn(j1, n)
			forn(j2, n)
				forn(it, 2)
				{
					int& cur = d[i][j1][j2][it];
					if (cur == -INF) continue;
					
					if (j1 < n - 1 && it == 0)
					{
						int& next = d[i][j1 + 1][j2][0];
						int add = (j1 + 1 == j2 ? 0 : a[i][j1 + 1]);
						next = max(next, cur + add);
					}
					
					if (it == 0)
					{
						int& next = d[i][j1][j2][1];
						next = max(next, cur);
					}
					
					if (j2 < n - 1 && it == 1)
					{
						int& next = d[i][j1][j2 + 1][1];
						int add = (j2 + 1 > j1 ? a[i][j2 + 1] : 0);
						next = max(next, cur + add);
					}
					
					if (i < n - 1 && it == 1)
					{
						int& next = d[i + 1][min(j1, j2)][max(j1, j2)][0];
						int add = a[i + 1][j1] + (j2 == j1 ? 0 : a[i + 1][j2]);
						next = max(next, cur + add);
					}
				}
	}
	
	int ans = -INF;
	forn(it, 2)
		ans = max(ans, d[n - 1][n - 1][n - 1][it]);
		
	cout << ans << endl;	
	
	return 0;
}