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

const int N = 100005;

int w[N], s[N];

int main()
{
	#ifdef LOCAL_TEST
		freopen("c.in","r",stdin);
//		freopen("c.out","w",stdout);
	#endif
	int n, l, r, Ql, Qr;
	scanf("%d%d%d%d%d", &n, &l, &r, &Ql, &Qr);
	int ans = lim * 2;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &w[i]);
		s[i] = s[i - 1] + w[i];
	}
	for (int i = 0; i <= n; ++i)
	{
		int tmp = s[i] * l;
		tmp += (s[n] - s[i]) * r;
		int left = i;
		int right = n - i;
		if (abs(left - right) > 1)
		{
			if (left > right)
				tmp += Ql * (left - right - 1);
			else
				tmp += Qr * (right - left - 1);
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
    return 0;
}