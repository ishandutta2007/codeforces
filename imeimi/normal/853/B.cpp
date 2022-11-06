#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
typedef long long llong;

struct flight {
	int day;
	int city;
	int cost;
	bool operator<(const flight &x) const {
		return day < x.day;
	}
	bool operator!=(const flight &x) const {
		return day != x.day || city != x.city || cost != x.cost;
	}
};

int n, m, k;
vector<flight> st;
//bool visit[100001];
vector<flight> ed;

flight ds[100001];
deque<flight> de[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	int a, b, c, d;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c >> d;
		if (b == 0) {
			ed.push_back({ a, c, d });
		}
		else {
			st.push_back({ a, b, d });
		}
	}
	sort(st.begin(), st.end());
	sort(ed.begin(), ed.end());
	for (int i = 0; i < ed.size(); ++i) {
		while (!de[ed[i].city].empty() && ed[i].cost <= de[ed[i].city].back().cost)
			de[ed[i].city].pop_back();// , visit[i] = true;
		de[ed[i].city].push_back(ed[i]);
	}
	llong endcost = 0;
	for (int i = 1; i <= n; ++i) {
		if (de[i].empty()) {
			printf("-1\n");
			return 0;
		}
		endcost += de[i].front().cost;
	}
	llong stcost = 0;
	int sday = 0;
	int cnt = 0;
	int p = 0;
	llong ans = -1;
	for (flight i : st) {
		if (ds[i.city].city == 0) {
			ds[i.city] = i;
			stcost += i.cost;
			sday = i.day;
			++cnt;
		}
		else if (ds[i.city].cost <= i.cost) {
			continue;
		}
		else {
			sday = i.day;
			stcost -= ds[i.city].cost;
			stcost += i.cost;
			ds[i.city] = i;
		}
		if (cnt < n) continue;
		while (ed[p].day <= sday + k) {
			if (ed[p] != de[ed[p].city].front()) {
				++p;
				continue;
			}
			endcost -= ed[p].cost;
			de[ed[p].city].pop_front();
			if (de[ed[p].city].empty()) {
				printf("%lld\n", ans);
				return 0;
			}
			ed[p] = de[ed[p].city].front();
			endcost += ed[p].cost;
			++p;
		}
		if (ans == -1ll || stcost + endcost < ans) {
			ans = stcost + endcost;
		}
	}
	printf("%lld\n", ans);
	return 0;
}