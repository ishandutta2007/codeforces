#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef double ld;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define unq(x) {sort(all(x));(x).resize(unique(all(x))-(x).begin());}
#define lb lower_bound
const int inf = 1e9+100500;
const int maxn = 10;

const int p10[] = {1, 10, 100, 1000, 10000, 100000};
const int x[] = {2, 3, 3, 4, 4, 4};
const int y[] = {1, 1, 2, 1, 2, 3};
const int stop[] = {0, 0, 0, 1, 3, 6};

int mlog(int x)
{
	if (x < 100) return 2;
	if (x < 1000) return 3;
	if (x < 10000) return 4;
	return 5;
}
bool prime(int x)
{
	for (int i = 2; i*i <= x; i++)
		if (x%i==0) return false;
	return true;
}
int digit(int x, int k)
{
	forn(i, k) x /= 10;
	return x%10;
}
int d[100005][maxn];
void comp()
{
	fore(i, 2, 99999) if (prime(i))
	{
		forn(j, 5)
			d[i%p10[j] + i / p10[j+1] * p10[j] ][j]++;
	}
}

int n;
int a[maxn][maxn];
int get(int lim = n)
{
	/*if (lim != n)
	{
		cout << "lim = " << lim << endl;
		forn(i, n)
		{
			forn(j, n) cout << a[i][j];
			cout << endl;
		}
	}*/
	int pr = 1;
	for (int i = 1; i < lim; i++)
	{
		int x = 0;
		forn(j, n) if (j != i)
			x = x*10 + a[i][j];
		pr *= d[x][n-i-1];
		//cerr << d[x][n-i-1] << endl;
		if (pr == 0)
			break;
	}
	//cout << "var = " << pr << endl;
	//cout << endl;
	return pr;
}
i64 go(int pos)
{
	if (pos == stop[n])
		return get();
	//prn1 failed cos of bad indexing system
	/*if (pos == stop[n-1] && !get(x[pos]))
	{
		cerr << "worked\n";
		return 0;
	}*/
	i64 s = 0;
	fore(i, 0, 9)
	{
		if (x[pos] == n-1 && i != 2 && i%2 == 0)
			continue;
		a[x[pos]][y[pos]] = a[y[pos]][x[pos]] = i;
		s += go(pos+1);
	}
	return s;
}
void solve()
{
	int x;
	cin >> x;
	n = mlog(x);
	forn(i, n) a[i][0] = a[0][i] = digit(x, n-i-1);
	cout << go(0) << endl;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	comp();
	//cerr << "computation done!\n";
	int t;
	cin >> t;
	forn(i, t)
		solve();
		
	return 0;
}