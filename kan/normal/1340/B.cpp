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

const int A = 10;

const int maxn = 2005;
const int inf = maxn * 10;

string digtorep[A];
bitset<maxn> can[maxn];
int dist[maxn][A];
char s[maxn];
int n, k;

int getdist(string a, string b)
{
	assert(a.length() == b.length());
	int ans = 0;
	for (int i = 0; i < (int)a.length(); i++)
	{
		if (b[i] == '1' && a[i] == '0') return inf;
		if (a[i] == '1' && b[i] == '0') ans++;
	}
	return ans;
}

int main()
{
	digtorep[0] = "1110111";
	digtorep[1] = "0010010";
	digtorep[2] = "1011101";
	digtorep[3] = "1011011";
	digtorep[4] = "0111010";
	digtorep[5] = "1101011";
	digtorep[6] = "1101111";
	digtorep[7] = "1010010";
	digtorep[8] = "1111111";
	digtorep[9] = "1111011";
	scanf("%d%d", &n, &k);
	for (int i =0; i < n; i++)
	{
		scanf("%s", s);
		string cur = string(s);
		for (int d =0 ; d < A; d++) dist[i][d] = getdist(digtorep[d], cur);
	}
	can[n][0] = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int d = 0; d < A; d++) if (dist[i][d] != inf)
		{
			can[i] |= (can[i + 1] << dist[i][d]);
		}
	}
	if (!can[0][k])
	{
		printf("%d\n", -1);
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int d = A - 1; d >= 0; d--) if (dist[i][d] <= k && can[i + 1][k - dist[i][d]])
		{
			printf("%d", d);
			k -= dist[i][d];
			break;
		}
	}
	printf("\n");
    return 0;
}