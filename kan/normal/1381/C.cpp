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

vector<int> pos[maxn];
int n, bulls, cows;
priority_queue<pair2<int>> freq;
int a[maxn], b[maxn];
vector<pair2<int>> all;

void solve()
{
	scanf("%d%d%d", &n, &bulls, &cows);
	cows -= bulls;
	for (int i =0 ; i < n + 1; i++) pos[i].clear();
	for (int i =0 ; i < n; i++)
	{
		scanf("%d", &b[i]);
		b[i]--;
		pos[b[i]].pb(i);
	}
	for (int i = 0; i < n; i++) a[i] = -1;
	int missing_color = -1;
	while (!freq.empty()) freq.pop();
	for (int i = 0; i < n + 1; i++)
	{
		if (pos[i].empty()) missing_color = i;
		freq.push({(int)pos[i].size(), i});
	}
	assert(missing_color != -1);
	for (int i =0 ; i < bulls; i++)
	{
		int color = freq.top().se;
		freq.pop();
		a[pos[color].back()] = color;
		pos[color].pop_back();
		freq.push({(int)pos[color].size(), color});
	}
	all.clear();
	int max_occ = freq.top().fi;
	while (!freq.empty())
	{
		int color = freq.top().se;
		freq.pop();
		//cout << color << ' ' << (int)pos[color].size() << endl;
		for (auto t : pos[color]) all.pb({color, t});
	}
	//cout << "f " << (int)all.size() << ' ' << max_occ << endl;
	int max_cows = (int)all.size();
	if (2 * max_occ > (int)all.size()) max_cows -= 2 * max_occ - (int)all.size();
	if (cows > max_cows)
	{
		printf("NO\n");
		return;
	}
	int shift = (int)all.size() / 2;
	for (int i = 0; i < (int)all.size(); i++)
	{
		int j = (i + shift) % (int)all.size();
		int color = all[j].fi;
		if (all[i].fi == all[j].fi || cows == 0) color = missing_color;
		if (color != missing_color) cows--;
		a[all[i].se] = color;
	}
	printf("Yes\n");
	for (int i = 0; i < n; i++) printf("%d ", a[i] + 1);
	printf("\n");
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