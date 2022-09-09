#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 2005;

vector<int> need;
bool ison[maxn];
int n;

int main()
{
	scanf("%d", &n);
	int sqroot = 1;
	int maxcnt = 0;
	for (int i = 2; i * i <= n; i++)
	{
		int nblocks = n / i;
		int curcnt = (nblocks - 1) * (i - 1) + max(0, n - nblocks * i - 1);
		//cout << i << ' ' << curcnt << endl;
		if (curcnt > maxcnt)
		{
			sqroot = i;
			maxcnt = curcnt;
		}
	}
	//cout << sqroot << endl;
	for (int i = 0; i < n; i += sqroot)
	{
		for (int j = 0; j < sqroot - 1 && i + j < n - 1; j++) need.pb(i + j);
	}
	while (true)
	{
		//for (int i = 0; i < n; i++) printf("%d", ison[i]);
		//printf("\n");
		vector<int> can;
		for (auto t : need) if (!ison[t]) can.pb(t);
		if ((int)can.size() < sqroot) break;
		can.resize(sqroot);
		for (auto t : can) ison[t] = true;
		printf("%d", (int)sqroot);
		for (auto t : can) printf(" %d", t + 1);
		printf("\n");
		fflush(stdout);
		int wh;
		scanf("%d", &wh);
		wh--;
		for (int i = 0; i < sqroot; i++) ison[(wh + i) % n] = false;
	}
	printf("0\n");
	fflush(stdout);
    return 0;
}