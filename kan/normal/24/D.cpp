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

#define beta beta_sdf

const int maxn = 1005;

ld a[maxn], b[maxn], c[maxn], f[maxn];
ld beta[maxn], alpha[maxn];
ld x[maxn];
ld ans[maxn];
int n, m, r, cc;

void solverow(int n)
{
	for (int i = 0; i < n; i++)
	{
		c[i] = 1;
		if (i == 0)
		{
			b[i] = -0.5;
		} else if (i == n - 1)
		{
			a[i] = -0.5;
		} else
		{
			b[i] = -(ld)1 / 3;
			a[i] = -(ld)1 / 3;
		}
	}
	alpha[1] = -(ld)b[0] / c[0];
	beta[1] = (ld)f[0] / c[0];
	for (int i = 1; i < n - 1; i++)
	{
		alpha[i + 1] = -(ld)b[i] / ((ld)a[i] * alpha[i] + c[i]);
		beta[i + 1] = (ld)(f[i] - (ld)a[i] * beta[i]) / ((ld)a[i] * alpha[i] + c[i]);
	}
	x[n - 1] = (ld)(f[n - 1] - (ld)a[n - 1] * beta[n - 1]) / ((ld)a[n - 1] * alpha[n - 1] + c[n - 1]);
	for (int i = n - 2; i >= 0; i--) x[i] = alpha[i + 1] * x[i + 1] + beta[i + 1];
}

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%d%d", &r, &cc);
	if (m == 1)
	{
		cout << 2 * (n - r) << endl;
		return 0;
	}
	
	for (int i = 0; i < m; i++) ans[i] = 0;
	for (int xx = n - 1; xx >= r; xx--)
	{
		for (int i = 0; i < m; i++)
		{
			if (i == 0 || i == m - 1) f[i] = (ld)3 / 2 + (ld)1 / 2 * ans[i];
			else f[i] = (ld)4 / 3 + (ld)1 / 3 * ans[i];
		}
		solverow(m);
		//for (int i = 0; i < m; i++) cout << x[i] << ' ';
		//cout << endl;
		for (int i = 0; i < m; i++) ans[i] = x[i];
	}
	printf("%.20lf\n", (double)ans[cc - 1]);
	
    return 0;
}