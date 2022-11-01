#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define tr(c, it) for (typeof (c).begin() it = (c).begin(); it != (c).end(); it++)
const int maxn = 200500;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double ld;
const int inf = 1e9+100500;
#define all(x) (x).begin(), (x).end()
typedef long long i64;
const ld eps = 1e-9;

int a[maxn];
int n;

int main()
{
	cin >> n;
	forn(i, n) cin >> a[i];
	sort(a, a+n);
	int t = -350;
	int res = 0;
	forn(i, n)
	{
		t += a[i];
		if (t > 360)
		{
			cout << i << " " << res << endl;
			return 0;
		}
		if (t >= 0)
			res += t;
	}
	cout << n << " " << res << endl;
}