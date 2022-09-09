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

const int maxn = 100005;

int a[maxn], b[maxn], c[maxn];
int n, l, r;

int main()
{
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i =0 ; i < n; i++) scanf("%d", &c[i]);
	for (int i = 0; i < n; i++) b[i] = a[i] + c[i] - 1;
	int mx = *max_element(b, b + n);
	int dec = max(0, mx - r);
	bool ok = true;
	for (int i =0 ; i < n; i++)
	{
		b[i] -= dec;
		if (b[i] < l) ok = false;
	}
	if (!ok)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i =0 ; i < n; i++) cout << b[i] << ' ';
	cout << endl;
	
    return 0;
}