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

int n;

vector<int> fact(int n)
{
	vi res;
	for (int i = 1; i * i <= n; i++)
		if (n%i == 0)
		{
			res.pb(i);
			res.pb(n/i);
		}
	return res;
};
i64 get (i64 a, i64 b, i64 c)
{
	return a*b*c-(a-1ll)*(b-2ll)*(c-2ll);
}
int main()
{
	cin >> n;
	vi t = fact(n);
	i64 mx = -1, mn = 1e18;
	forn(i, t.size()) forn(j, t.size())
		if ((i64)t[i] * t[j] <= (i64)n && n%(t[i]*t[j]) == 0)
		{
			i64 t1 = get(t[i]+1, t[j]+2, n/(t[i]*t[j])+2);
			mx = max(mx, t1);
			mn = min(mn, t1);
		}
	cout << mn << " " << mx << endl;
	
	return 0;
}