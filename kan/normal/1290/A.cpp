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

const int maxn = 35005;
const int inf = 1e9+ 9;

int a[maxn];
int n, m, k;

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		scanf("%d%d%d", &n, &m, &k);
		m--;
		k = min(k, m);
		for (int i =0 ; i < n; i++) scanf("%d", &a[i]);
		int nthey = m - k;
		int answer = -inf;
		for (int leftme = 0; leftme <= k; leftme++)
		{
			int curans = inf;
			for (int leftthey = 0; leftthey <= nthey; leftthey++)
			{
				int left = leftme + leftthey;
				int right = k - leftme + nthey - leftthey;
				curans = min(curans, max(a[left], a[n - right - 1]));
			}
			answer = max(answer, curans);
		}
		printf("%d\n", answer);
	}
    return 0;
}