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

const int maxk = 22;

int cnt[maxk];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		for (int k = 0; k < maxk; k++)
		{
			cnt[k] += (x % 2);
			x /= 2;
		}
	}
	ll answer = 0;
	for (int i = 0; i < n; i++)
	{
		int cur = 0;
		for (int k = maxk - 1; k >= 0; k--)
		{
			cur *= 2;
			if (cnt[k] > 0)
			{
				cur++;
				cnt[k]--;
			}
		}
		//cout << cur << endl;
		answer = answer + (ll)cur * cur;
	}
	printf("%lld\n", answer);
    return 0;
}