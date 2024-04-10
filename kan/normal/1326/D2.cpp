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

char s[maxn];
int m[maxn];
int n;
int ans[maxn];

void solve()
{
	scanf("%s", s);
	n = strlen(s);
	int k = 0;
	while (k < n - k - 1 && s[k] == s[n - k - 1]) k++;
	if (k >= n - k - 1)
	{
		printf("%s\n", s);
		return;
	}
	pair<int, pair2<int>> answer = {2 * k + 1, {k, k}};
	m[0] = 1;
	int l = 0;
	int r = 0;
	for (int i = 1; i < n; i++)
	{
		m[i] = 0;
		if (i <= r) m[i] = min(r - i + 1, m[l + (r - i)]);
		while (i + m[i] < n - k && i - m[i] >= k && s[i + m[i]] == s[i - m[i]]) m[i]++;
		if (i + m[i] - 1 > r)
		{
			r = i + m[i] - 1;
			l = i - m[i] + 1;
		}
		
		//for (int j = 0; j < m[i]; j++) assert(s[i + j] == s[i - j]);
		//assert(i - m[i] < 0 || i + m[i] >= n || s[i + m[i]] != s[i - m[i]]);
		
		if (i >= k && i - m[i] + 1 <= k) answer = max(answer, {2 * k + 2 * (i - k) + 1, {k, i + (i - k)}});
		if (i <= n - 1 - k && i + m[i] - 1 >= n - 1 - k)
			answer = max(answer, {2 * k + 2 * (n - 1 - k - i) + 1, {i - (n - 1 - k - i), (n - 1 - k)}});
		//cout << i << ' ' << answer.fi << endl;
	}
	m[0] = 0;
	l = 0;
	r = 0;
	for (int i = 1; i < n; i++)
	{
		m[i] = 0;
		if (i <= r) m[i] = min(r - i + 1, m[l + (r - i) + 1]);
		while (i + m[i] < n - k && i - m[i] - 1 >= k && s[i + m[i]] == s[i - m[i] - 1]) m[i]++;
		if (i + m[i] - 1 > r)
		{
			r = i + m[i] - 1;
			l = i - m[i];
		}

		//for (int j = 0; j < m[i]; j++) assert(s[i + j] == s[i - j - 1]);
		//assert(i - m[i] - 1 < 0 || i + m[i] >= n || s[i + m[i]] != s[i - m[i] - 1]);
		
		if (i > k && i - m[i] <= k) answer = max(answer, {2 * k + 2 * (i - k), {k, i + (i - k) - 1}});
		if (i <= n - 1 - k && i + m[i] - 1 >= n - 1 - k)
			answer = max(answer, {2 * k + 2 * (n - 1 - k - i + 1), {i - (n - 1 - k - i) - 1, (n - 1 - k)}});
	}
	//printf("%d\n", answer.fi);
	//cout << answer.se.fi << ' ' << answer.se.se << endl;
	int len = 0;
	for (int i =0 ; i < k; i++) printf("%c", s[i]), ans[len++] = s[i];
	for (int i = answer.se.fi; i <= answer.se.se; i++) printf("%c", s[i]), ans[len++] = s[i];
	for (int i = n - 1 - k + 1; i < n; i++) printf("%c", s[i]), ans[len++] = s[i];
	printf("\n");
	assert(len == answer.fi);
	for (int i = 0; i < len; i++) assert(ans[i] == ans[len - i - 1]);
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T =0 ; T < NT; T++)
	{
		solve();
	}
    return 0;
}