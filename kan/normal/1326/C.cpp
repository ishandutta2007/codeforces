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

const int maxn = 200005;

const int MOD = 998244353;

inline int add(int a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

inline int sub(int a, int b)
{
	a -= b;
	if (a < 0) a += MOD;
	return a;
}

int a[maxn];
pair2<int> b[maxn];
//int ans[maxn][2];
vector<int> pos;
int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i =0 ; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i <n; i++) b[i] = {a[i], i};
	sort(b, b + n);
	reverse(b, b + n);
	ll sum = 0;
	for (int i =0 ; i < k; i++)
	{
		sum += b[i].fi;
		pos.pb(b[i].se);
	}
	sort(all(pos));
	int ans = 1;
	for (int i = 1; i < (int)pos.size(); i++) ans = ((ll)ans * (pos[i] - pos[i - 1])) % MOD;
	cout << sum << ' ' << ans << endl;
	//int t = k;
	//while (t < n && b[t].fi == b[t - 1].fi) t++;
	//int secondlastbig = -1;
	//int lastbig = -1;
	//int lastsmall = -1;
	//ans[0][0] = 1;
	//for (int i = 0; i < n; i++)
	//{
		//if (a[i] > b[k - 1].fi)
		//{
			//secondlastbig = lastbig;
			//lastbig = i;
		//}
		//if (a[i] == b[k - 1].fi) lastsmall = i;
		//int curans = 0;
		//if (lastbig >= 0) curans = add(curans, ans[lastbig][0]);
		//if (secondlastbig >= 0) curans = sub(curans, ans[secondlastbig][0]);
		//ans[i + 1][0] = add(ans[i][0], curans);
		//ans[i + 1][1] = ans[i][1];
		//if (lastsmall > lastbig)
		//{
			//ans[i + 1][1] = add(ans[i + 1][1], ans[lastsmall][0]);
			//if (lastbig >= 0) ans[i + 1][1] = sub(ans[i + 1][1], ans[lastbig][0]);
		//}
	//}
	//printf("%lld %d\n", sum, ans[n][1]);
    return 0;
}