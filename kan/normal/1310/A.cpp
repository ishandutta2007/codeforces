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

pair2<int> who[maxn];
int t[maxn];
int a[maxn];
priority_queue<int> cur;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		who[i] = {a[i], i};
	}
	sort(who, who + n);
	for (int i = 0; i < n; i++) scanf("%d", &t[i]);
	int curp = 0;
	ll answer = 0;
	ll cursum = 0;
	for (int i = 1; ; i++)
	{
		if (cur.empty())
		{
			if (curp == n) break;
			i = who[curp].fi;
		}
		while (curp < n && who[curp].fi == i)
		{
			cursum += t[who[curp].se];
			cur.push(t[who[curp].se]);
			curp++;
		}
		assert(!cur.empty());
		cursum -= cur.top();
		cur.pop();
		answer += cursum;
	}
	cout << answer << endl;
    return 0;
}