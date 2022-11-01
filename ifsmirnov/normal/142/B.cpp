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

int main()
{
	int n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);
	if (n == 1 || m == 1)
		cout << max(n, m) << endl;
	else if (n == 2)
		cout << 2 * (m/4*2 + min(2, m%4)) << endl;
	else
		cout << (n*m+1)/2 << endl;
}