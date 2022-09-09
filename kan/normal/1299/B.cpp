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

struct pt
{
	int x, y;
};

inline pt operator-(const pt &a, const pt &b)
{
	return {a.x - b.x, a.y - b.y};
}

inline pt operator-(const pt &a)
{
	return {-a.x, -a.y};
}

inline bool operator<(const pt &a, const pt &b)
{
	return mp(a.x, a.y) < mp(b.x, b.y);
}

const int maxn = 100005;

pt p[maxn];
set<pt> dirs;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y);
	p[n] = p[0];
	for (int i =0; i < n; i++) dirs.insert(p[i + 1] - p[i]);
	bool ok = true;
	for (int i = 0; i < n; i++) if (!dirs.count(p[i] - p[i + 1])) ok = false;
	cout << (ok ? "YES" : "NO") << endl;
    return 0;
}