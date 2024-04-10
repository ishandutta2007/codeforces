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

const int maxn = 305;

char s[maxn][maxn];
int cnt[3];
int n;

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	for (int i = 0; i < 3; i++) cnt[i] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) if (s[i][j] == 'X') cnt[(i + j) % 3] ++;
	}
	int id = min_element(cnt, cnt + 3) - cnt;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) if (s[i][j] == 'X' && (i + j) % 3 == id)
		{
			s[i][j] = 'O';
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", s[i]);
	}
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		solve();
	}
    return 0;
}