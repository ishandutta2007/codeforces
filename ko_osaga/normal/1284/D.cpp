#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>
#define all(x) (x).begin(), (x).end()
#define xx first
#define yy second

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

struct Event
{
	Event(int t_, int s_, int e_, int isIn_) : t(t_), s(s_), e(e_), isIn(isIn_) {}
	int t;
	int s, e;
	int isIn;

	bool operator<(const Event& rhs) {
		if (t == rhs.t)
			return isIn < rhs.isIn;

		return t < rhs.t;
	}
};

bool check(int n, vector<int>& sa, vector<int>& ea, vector<int>& sb, vector<int>& eb)
{
	multiset<int> s, e;

	vector<Event> events;

	for (int i = 0; i < n; i++)
	{
		events.emplace_back(sa[i], sb[i], eb[i], 1);
		events.emplace_back(ea[i] + 1, sb[i], eb[i], 0);
	}

	sort(all(events));

	for (int i = 0; i < 2 * n; i++)
	{
		if (events[i].isIn)
		{
			if (!s.empty())
			{
				int maxS = *s.rbegin();
				int minE = *e.begin();

				if (maxS > events[i].e || minE < events[i].s)
					return false;
			}

			s.insert(events[i].s);
			e.insert(events[i].e);
		}
		else
		{
			s.erase(s.find(events[i].s));
			e.erase(e.find(events[i].e));
		}
	}

	return true;
}

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> sa(n), ea(n), sb(n), eb(n);

	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d", &sa[i], &ea[i], &sb[i], &eb[i]);

	if (check(n, sa, ea, sb, eb) && check(n, sb, eb, sa, ea))
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}