#include <iostream>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
typedef vector<int> vi;
typedef long long i64;
typedef pair<i64, int> pii;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
const int inf = 1e9+100500;
const int maxn = 100500;

i64 cur = 0;
vector<pii> a;
i64 p[maxn];
i64 res[10];
int n;

int main()
{
	cin >> n;
	forn(i, n) cin >> p[i];
	a.resize(5);
	forn(i, 5) cin >> a[i].fi, a[i].se = i;
	sort(a.begin(), a.end(), greater<pii>());
	forn(i, n)
	{
		cur += p[i];
		forn(j, 5)
		{
			res[a[j].se] += cur/a[j].fi;
			cur %= a[j].fi;
		}
	}
	forn(i, 5) cout << res[i] << " ";
	cout << endl << cur << endl;
	
	return 0;
}