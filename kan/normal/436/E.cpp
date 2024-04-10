#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 300005;
const ll inf = 1e18;

struct tlvl
{
	int a, b, id;
};

inline bool cmpa(const tlvl &a, const tlvl &b)
{
	return a.a < b.a;
}

inline bool cmpb(const tlvl &a, const tlvl &b)
{
	return a.b < b.b;
}

set<pair<int, int> > bestin, bestout;
tlvl l[maxn];
int ans[maxn];
ll cursum;
int n, W;

inline void add(pair<int, int> t)
{
// 	cout << "add " << t.first << ' ' << t.second << endl;
	bestout.insert(t);
	while (bestout.size() > 0 && bestin.size() > 0 && *bestout.begin() < *bestin.rbegin())
	{
// 		cout << "add " << bestin.rbegin()->first << ' ' << bestout.begin()->first << endl;
		auto to_out = *bestin.rbegin();
		bestin.erase(to_out);
		auto to_in = *bestout.begin();
		bestout.erase(to_in);
		bestin.insert(to_in);
		bestout.insert(to_out);
		cursum += to_in.first - to_out.first;
	}
}

inline void rem(pair<int, int> t)
{
	if (bestin.count(t)) cursum -= t.first;
	bestin.erase(t);
	bestout.erase(t);
}

inline void make_cnt(int kv)
{
// 	cout << "make_cnt << 
	while ((int)bestin.size() > kv)
	{
		auto to_out = *bestin.rbegin();
		bestin.erase(to_out);
		bestout.insert(to_out);
		cursum -= to_out.first;
	}
	while ((int)bestin.size() < kv)
	{
		auto to_in = *bestout.begin();
		bestout.erase(to_in);
		bestin.insert(to_in);
// 		cout << "make_cnt " << bestin.size() << ' ' << kv << ' ' << to_in.first << endl;
		cursum += to_in.first;
	}
}

int main()
{
	scanf("%d%d", &n, &W);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &l[i].a, &l[i].b);
		l[i].id = i;
	}
	sort(l, l + n, cmpa);
	ll answer = inf;
	int whans = -2;
	if (W <= n)
	{
		answer = 0;
		for (int i = 0; i < W; i++) answer += l[i].a;
		whans = -1;
	}
	sort(l, l + n, cmpb);
	for (int i = 0; i < n; i++) add(make_pair(l[i].a, l[i].id));
	ll curadd = 0;
	for (int i = 0; i < n; i++)
	{
// 		cout << i << endl;
		rem(make_pair(l[i].a, l[i].id));
// 		cout << "rem " << endl;
		if (n + i + 1 >= W && W - 2 - i >= 0)
		{
// 			cout << "in " << i << ' ' << n + i + 1 << endl;
			make_cnt(W - 2 - i);
// 			cout << "sdf" << endl;
			ll curans = l[i].b + cursum + curadd;
// 			cout << i << ' ' << curans << endl;
			if (curans < answer)
			{
				answer = curans;
				whans = i;
			}
		}
		curadd += l[i].a;
// 		cout << "to_add " << endl;
		add(make_pair(l[i].b - l[i].a, l[i].id));
// 		cout << i << endl;
// 		if ((i & 127) == 0) cerr << i << endl;
	}
	if (whans == -1)
	{
		sort(l, l + n, cmpa);
		for (int i = 0; i < W; i++) ans[l[i].id] = 1;
	} else
	{
		bestin.clear();
		bestout.clear();
		for (int i = 0; i < whans; i++)
		{
			add(make_pair(l[i].b - l[i].a, l[i].id));
			ans[l[i].id] = 1;
		}
		ans[l[whans].id] = 2;
		for (int i = whans + 1; i < n; i++)
		{
			add(make_pair(l[i].a, l[i].id));
			ans[l[i].id] = 0;
		}
		make_cnt(W - 2 - whans);
		for (auto it : bestin) ans[it.second]++;
	}
	printf(LLD "\n", answer);
	for (int i = 0; i < n; i++) printf("%d", ans[i]);
	return 0;
}