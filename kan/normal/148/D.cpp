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

const int DRAG = 0;
const int PRINC = 1;

ld ans[maxn][maxn][2];
int nw, nb;

int main()
{
	scanf("%d%d", &nw, &nb);
	for (int i = 0; i <= nb; i++)
	{
		ans[0][i][DRAG] = 1;
		ans[0][i][PRINC] = 0;
	}
	for (int i = 1; i <= nw; i++)
	{
		ans[i][0][DRAG] = 1;
		ans[i][0][PRINC] = 1;
		for (int j = 1; j <= nb; j++)
		{
			ans[i][j][DRAG] = (ld)i / (i + j);
			ld prob = (ld)j / (i + j);
			int k = j - 1;
			if (k > 0) ans[i][j][DRAG] += prob * ((ld)k / (i + k)) * (1 - ans[i][k - 1][PRINC]);
			if (i > 0) ans[i][j][DRAG] += prob * ((ld)i / (i + k)) * (1 - ans[i - 1][k][PRINC]);

			ans[i][j][PRINC] = (ld)i / (i + j);
			prob = (ld)j / (i + j);
			ans[i][j][PRINC] += prob * (1 - ans[i][j - 1][DRAG]);
		}
	}
	printf("%.20lf\n", (double)ans[nw][nb][PRINC]);
    return 0;
}