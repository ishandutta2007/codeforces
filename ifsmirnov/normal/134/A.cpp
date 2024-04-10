#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 200500;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double ld;
const int inf = 1e9+100500;
const ld eps = 1e-9;
typedef long long i64;

int a[maxn], n;
i64 s;

int main()
{
	//freopen("input.txt", "r", stdin);
	ios :: sync_with_stdio(0);
	
	cin >> n;
	forn(i, n) cin >> a[i];
	s = 0;
	forn(i, n) s += a[i];
	vi res;
	if (s%n == 0)
	{
		s /= n;
		forn(i, n) if (a[i] == s) res.pb(i);
	}
	cout << res.size() << endl;
	forn(i, res.size()) cout << res[i] + 1 << " ";
	
	return 0;
}