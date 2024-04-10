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
const int maxn = 200500;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double ld;
const int inf = 1e9+100500;
typedef long long i64;
const ld eps = 1e-9;
#define le(x, y) ((x)<(y)+eps)

int main()
{
	ios :: sync_with_stdio(false);
	//freopen("input.txt","r",stdin);
	
	int n;
	ld  R, r;
	cin >> n >> R >> r;
	
	if (n == 0)
		cout << "YES";
	else if (n == 1)
	{
		if (le(r, R))
			cout << "YES";
		else
			cout << "NO";
	}
	else if (!le(r*2, R))
		cout << "NO";
	else
	{
		ld alpha = asin(r/(R-r));
		if (le(alpha * n * 2, 2*M_PI))
			cout << "YES";
		else
			cout << "NO";
	}
	
	return 0;
}