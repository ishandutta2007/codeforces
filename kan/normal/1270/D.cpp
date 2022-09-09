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

const int maxn = 505;

int a[maxn];
int n, k;
vector<pair2<int>> middle;

pair2<int> ask(vector<int> &qs)
{
	printf("?");
	for (auto t : qs) printf(" %d", t + 1);
	printf("\n");
	fflush(stdout);
	int pos, val;
	scanf("%d", &pos);
	if (pos == -1) exit(0);
	scanf("%d", &val);
	pos--;
	return {pos, val};
}

void dofirst()
{
	vector<int> qs;
	for (int i = 0; i < n && (int)qs.size() < k; i++) if (a[i] == -1)
	{
		qs.pb(i);
	}
	pair2<int> ret = ask(qs);
	a[ret.fi] = ret.se;
}

int dosecond(vector<int> &others, int rem, int add0, int add1)
{
	vector<int> qs;
	for (auto t : others) if (t != rem) qs.pb(t);
	qs.pb(add0);
	qs.pb(add1);
	pair2<int> ret = ask(qs);
	return (ret.fi == add1);
}

int main()
{
	scanf("%d%d", &n, &k);
	if (k == 1)
	{
		printf("! %d\n", 1);
		return 0;
	}
	for (int i = 0; i < n; i++) a[i] = -1;
	
	for (int i = 0; i < n - (k - 1); i++)
	{
		dofirst();
	}
	
	for (int i = 0; i < n; i++) if (a[i] != -1)
	{
		middle.pb({a[i], i});
	}
	sort(all(middle));
	assert((int)middle.size() >= 2);
	int p0 = middle[0].se;
	int p1 = middle[1].se;
	vector<int> others;
	for (int i = 0; i < n; i++) if (a[i] == -1) others.pb(i);
	assert((int)others.size() == k - 1);
	int answer = 0;
	for (auto t : others)
	{
		answer += dosecond(others, t, p0, p1);
	}
	answer++;
	printf("! %d\n", answer);
    return 0;
}