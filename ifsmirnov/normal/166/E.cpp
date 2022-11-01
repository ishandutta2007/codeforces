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
const int mod = 1e9+7;
inline int madd (int x, int y) {return (x+y)%mod;}

int main()
{
	int n;
	cin >> n;
	int a=0, b=0, c=0, d=1;
	forn(i, n)
	{
		int aa=madd(b, madd(c, d));
		int bb=madd(a, madd(c, d));
		int cc=madd(b, madd(a, d));
		int dd=madd(a, madd(c, b));
		a=aa,b=bb,c=cc,d=dd;
	}
	cout << d << endl;
}