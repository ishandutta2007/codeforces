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

const int maxn = 500005;

vector<int> gr[maxn];
vector<int> tails[maxn], addbelow[maxn];
int n;
int anseven[maxn], ansstar[maxn], answer[maxn];
int longest[maxn];
int ansodd[maxn];
int diameter = 0;

void godown(int cur, int pr)
{
	for (auto t : gr[cur]) if (t != pr)
	{
		godown(t, cur);
		tails[cur].pb(longest[t] + 1);
	}
	sort(all(tails[cur]));
	if (tails[cur].empty()) longest[cur] = 0;
	else longest[cur] = tails[cur].back();
}

inline int getcnt(vector<int> &t, int x)
{
	return t.end() - lower_bound(all(t), x);
}

void calcans(int cur, int pr, int fromup)
{
	addbelow[cur].resize(tails[cur].size() + 1);
	for (auto t : gr[cur]) if (t != pr)
	{
		for (auto len : tails[t])
		{
			int cnt1 = getcnt(tails[t], len);
			int cnt2 = getcnt(tails[cur], len);
			int cnt = cnt1 + cnt2 - 1;
			anseven[len] = max(anseven[len], cnt);
			//cout << cur << " with " << t << ' ' << len << ' ' << anseven[len] << endl;
			
			int wh = (int)tails[cur].size() - cnt2;
			if (wh < (int)tails[cur].size() && tails[cur][wh] == len)
			{
			} else wh--;
			if (wh >= 0) addbelow[cur][wh] = max(addbelow[cur][wh], cnt1);
		}
		
		int push = fromup;
		if (longest[cur] == longest[t] + 1)
		{
			if (tails[cur].size() > 1) push = max(push, tails[cur][(int)tails[cur].size() - 2]);
		} else push = max(push, longest[cur]);
		diameter = max(diameter, push + 1 + longest[t]);
		tails[t].pb(push + 1);
		sort(all(tails[t]));
		calcans(t, cur, push + 1);
	}
	for (int i = (int)tails[cur].size() - 1; i >= 0; i--)
	{
		int len = tails[cur][i];
		if (2 * len + 1 < maxn) ansodd[len * 2 + 1] = max(ansodd[len * 2 + 1], 1 + getcnt(tails[cur], len + 1));
		anseven[len] = max(anseven[len], (int)tails[cur].size() - i);
		anseven[len] = max(anseven[len], (int)tails[cur].size() - i - 1 + addbelow[cur][i]);
		//cout << cur << ' ' << len << ' ' << anseven[len] << endl;
		//cout << addbelow[cur][i] << endl;
		ansstar[len] = max(ansstar[len], (int)tails[cur].size() - i);
		
		if (i > 0) addbelow[cur][i - 1] = max(addbelow[cur][i - 1], addbelow[cur][i]);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	godown(0, -1);
	calcans(0, -1, 0);
	
	for (int i = n; i > 0; i--) anseven[i - 1] = max(anseven[i - 1], anseven[i]);
	for (int i = n; i > 0; i--) ansstar[i - 1] = max(ansstar[i - 1], ansstar[i]);
	int modd = n;
	if (modd % 2 == 0) modd--;
	for (int i = modd; i > 1; i -= 2) ansodd[i - 2] = max(ansodd[i - 2], ansodd[i]);
	for (int i = 1; i <= n; i++) answer[i] = 1;
	for (int i = 0; i < n; i++) answer[1] = max(answer[1], 1 + (int)gr[i].size());
	for (int i = 1; i <= diameter; i++) answer[i] = max(answer[i], 2);
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0) answer[i] = max(answer[i], anseven[i / 2]);
		else
		{
			answer[i] = max(answer[i], ansstar[(i + 1) / 2]);
			answer[i] = max(answer[i], ansodd[i]);
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", answer[i]);
	printf("\n");
    return 0;
}