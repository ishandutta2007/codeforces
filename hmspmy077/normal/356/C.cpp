#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>

using namespace std;

typedef long long int64;
typedef long long LL;
typedef long double real;
typedef long double LD;

#define mp make_pair
#define PII pair<int, int>
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-8;
const double PI = acos(0.) * 2;
const int lim = 1000000000;
const int inf = ~0U >> 1;

template<class T> T abs(T x){return x < 0 ? -x : x;}

int a[10], b[10];

int solve(int p, int q)
{
	int ret = 0;
	for (int i = 0; i < 5; ++i)
		b[i] = a[i];
	int t = min(p, b[3]);
	p -= t;
	b[3] -= t;
	t = min(q, b[4]);
	q -= t;
	b[4] -= t;
	for (int i = 4; i; --i)
	{
		t = min(b[i], q);
		b[i] -= t;
		q -= t;
		ret += t * abs(i - 4);
	}
	for (int i = 4; i; --i)
	{
		t = min(b[i], p);
		b[i] -= t;
		p -= t;
		ret += t * abs(i - 3) * (i < 3);
	}
	return ret;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("c.in","r",stdin);
//		freopen("c.out","w",stdout);
	#endif
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		++a[x];
		sum += x;
	}
	int ans = lim;
	for (int i = 0; i <= n && i * 3 <= sum; ++i)
	{
		int j = (sum - i * 3) / 4;
		if (i * 3 + j * 4 != sum) continue;
		if (i + j > n) continue;
		ans = min(ans, solve(i, j));
	}
	if (ans == lim) ans = -1;
	cout << ans << endl;
    return 0;
}