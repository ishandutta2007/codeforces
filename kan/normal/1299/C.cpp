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

const int maxn = 1000006;

ll sum[maxn];
int cnt[maxn];
int a[maxn];
int elems;
vector<int> st;
int n;

inline bool issmaller(int a, int b)
{
	//return sum[a] / cnt[a] < sum[b] / cnt[b];
	ll wa = sum[a] * cnt[b];
	ll wb = sum[b] * cnt[a];
	if (wa != wb) return wa < wb;
	return a < b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	reverse(a, a + n);
	st.clear();
	for (int i = 0; i < n; i++)
	{
		sum[elems] = a[i];
		cnt[elems] = 1;
		while (!st.empty() && issmaller(st.back(), elems))
		{
			int lst = st.back();
			sum[elems] += sum[lst];
			cnt[elems] += cnt[lst];
			st.pop_back();
		}
		st.pb(elems);
		elems++;
	}
	while (!st.empty())
	{
		auto lst = st.back();
		st.pop_back();
		for (int i = 0; i < cnt[lst]; i++)
		{
			printf("%.20lf ", (double)sum[lst] / cnt[lst]);
		}
	}
    return 0;
}