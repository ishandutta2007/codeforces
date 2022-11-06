#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#include <numeric>

#define fi first
#define se second
#define fo(i,a,b) for (int i = a; i <= b; i ++)
#define fd(i,a,b) for (int i = a; i >= b; i --)
#define fe(i,x,y) for (int i = x, y = lnk[i]; i; i = nxt[i], y = lnk[i])
#define mkp make_pair
#define pb push_back
#define Fill(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define Bit(x,y) ((((x) >> (y)) & 1))
#define mit map<int,SI>::iterator
#define sit SI::iterator

using namespace std;
 
typedef long long LL;
typedef long double DB;
typedef pair <DB, DB> PD;
typedef pair <LL, LL> PLI;
typedef pair <PD, int> PDI;
typedef pair <int, int> PI;
typedef pair <int, PI> PII;
typedef pair <PI, PI> PIII;
typedef set <PI> SI;
typedef vector <int> VI;
 
int Read()
{
    char c; while (c = getchar(), (c != '-') && (c < '0' || c > '9'));
    bool neg = (c == '-'); int ret = (neg ? 0 : c - 48);
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
    return neg ? -ret : ret;
}

multiset <int> t;
map <int, int> a;
int N, b[500005];
LL ans;

int main()
{
	scanf("%d", &N);
	for (; N; N --)
	{
		int x = Read();
		++ a[x], ans += x;
	}
	for (map <int, int>::reverse_iterator it = a.rbegin(); it != a.rend(); it ++)
	{
		int x = it->fi, y = it->se, ms = min(N, (N + y) / 2), from = max(0, ms - y);
		fd (i, ms - 1, from)
			if (i < t.size()) b[i] = *t.begin(), t.erase(t.begin());
				else b[i] = 0;
		for (int i = from, j = N - i; i < j && i < ms; i ++)
			if (b[i] < x) b[i] = x; else if (-- j < ms) {
			    if (b[j]!=0){cout<<0<<endl;return 0;}
			    b[j] = max(0, 2 * x - b[i]);
			}
		t.insert(b + from, b + ms), N += y;
	}
	cout << ans - accumulate(t.begin(), t.end(), 0LL) << endl;
	return 0;
}