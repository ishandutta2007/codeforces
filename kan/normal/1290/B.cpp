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


int cnt[maxn][26];
char s[maxn];
int n;

int main()
{
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 26; j++) cnt[i + 1][j] = cnt[i][j];
		cnt[i + 1][s[i] - 'a']++;
	}
	int nq;
	
	scanf("%d", &nq);
	for (int q = 0; q < nq; q++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		int diff = 0;
		for (int i = 0; i < 26; i++)
		{
			int curcnt = cnt[r + 1][i] - cnt[l][i];
			if (curcnt > 0) diff++;
		}
		if (r == l || diff > 2 || s[l] != s[r]) printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}