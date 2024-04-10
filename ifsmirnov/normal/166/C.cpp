#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 100500;
#define pb push_back
#define mp make_pair
#define se second
#define fi first
typedef pair<int, int> pii;
typedef long long i64;

int main()
{
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	forn(i, n) cin >> a[i];
	int res = 0;
	for (;;res++)
	{
		sort(a.begin(), a.end());
		if (a[(a.size()-1)/2] == x)
		{
			cout << res << endl;
			return 0;
		}
		a.pb(x);
	}
	
	return 0;
}