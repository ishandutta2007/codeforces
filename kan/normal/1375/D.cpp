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

const int maxn = 1005;

int a[maxn];
bool isup[maxn];
bool was[maxn];
int n;
vector<int> answer;

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i =0; i < n; i++) isup[i] = false;
	answer.clear();
	while (true)
	{
		bool ok = true;
		for (int i = 1; i < n; i++) if (a[i] < a[i - 1]) ok = false;
		if (ok) break;
		for (int i = 0; i <= n; i++) was[i] = false;
		for (int i = 0; i < n; i++) was[a[i]] = true;
		int curmx = 0;
		while (was[curmx]) curmx++;
		if (curmx == n || isup[curmx])
		{
			assert(curmx != 0);
			answer.pb(curmx - 1);
			a[curmx - 1] = curmx;
			isup[curmx - 1] = true;
		} else
		{
			answer.pb(curmx);
			a[curmx] = curmx;
		}
		//for (int i = 0; i < n; i++) cout << a[i] << ' ';
		//cout << endl;
		
	}
	assert((int)answer.size() <= 2 * n);
	printf("%d\n", (int)answer.size());
	for (auto t : answer) printf("%d ", t + 1);
	printf("\n");
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T =0 ; T < NT; T++)
	{
		solve();
	}
    return 0;
}