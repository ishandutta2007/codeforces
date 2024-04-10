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
int a[maxn];

int main()
{
	cin >> n;
	forn(i, n) cin >> a[i];
	sort(a, a+n);
	if (a[n-1] == 1)
	{
		forn(i, n-1) cout << "1 ";
		cout << "2";
		return 0;
	}
	forn(i, n) if (i) cout << a[i-1] << " ";else cout << 1 << " ";
	
	return 0;
}