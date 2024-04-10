#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
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
const int maxn = 100500;
const int mod = 1000000007;
int madd (int x, int y) {return ((x+y)%mod+mod)%mod;}
int mmul (int x, int y) {return ((i64)x*y%mod+mod)%mod;}
int mpow (int x, int k)
{
	if (k == 0) return 1;
	int t = mpow(x, k/2);
	return mmul(mmul(t, t), k%2 ? x : 1);
}
int mdiv (int x, int y) {return mmul(x, mpow(y, mod-2));}

int n;
int bad[maxn];
int d[maxn][30];
string s;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> s;
	n = s.length();
	int m;
	cin >> m;
	forn(i, 26) bad[i] = -1;
	forn(i, m)
	{
		string t;
		cin >> t;
		bad[t[0]-'a'] = t[1]-'a';
		bad[t[1]-'a'] = t[0]-'a';
	}
	
	for (int i = 1; i <= n; i++)
	{
		int c = s[i-1]-'a';
		d[i][c] = inf;
		forn(k, 26) if (k != bad[c])
			d[i][c] = min(d[i][c], d[i-1][k]);
		forn(k, 26) if (k != c)
			d[i][k] = d[i-1][k] + 1;
	}
	
	int mn = inf;	
	forn(i, 26) mn = min(mn, d[n][i]);
	cout << mn << endl;
	
	return 0;
}