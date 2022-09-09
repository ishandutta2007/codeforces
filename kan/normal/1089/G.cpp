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

const int DD = 7;

int a[DD];

inline int get(int k, int start)
{
	int len = 0;
	while (k > 0 && start != 0)
	{
		len++;
		k -= a[start];
		start = (start + 1) % 7;
	}
	if (k == 0) return len;
	int sum = accumulate(a, a + DD, 0);
	int weeks = max(0, (k - sum) / sum);
	len += 7 * weeks;
	k -= sum * weeks;
	while (k > 0)
	{
		len++;
		k -= a[start];
		start = (start + 1) % 7;
	}
	return len;
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		int k;
		scanf("%d", &k);
		for (int i = 0; i < DD; i++) scanf("%d", &a[i]);
		int answer = k * 7;
		for (int start = 0; start < 7; start++)
		{
			answer = min(answer, get(k, start));
		}
		printf("%d\n", answer);
	}
    return 0;
}