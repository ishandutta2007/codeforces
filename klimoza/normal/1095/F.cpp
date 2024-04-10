#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")												
#pragma GCC optimize("rename-registers")									
#pragma GCC optimize("move-loop-invariants")								
#pragma GCC optimize("unswitch-loops")											
#pragma GCC optimize("function-sections")										
#pragma GCC optimize("data-sections")										
#pragma GCC optimize("branch-target-load-optimize")							
#pragma GCC optimize("branch-target-load-optimize2") 						
#pragma GCC optimize("btr-bb-exclusive")
#pragma comment(linker, "/stack:200000000")


#include <iostream>
#include <vector>	
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 998244353;
double eps = 1e-7;

vector<int> p;
vector<int> sz;

int get_par(int v) {
	if (p[v] == v) return v;
	p[v] = get_par(p[v]);
	return p[v];
}

void merge(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if (sz[b] < sz[a]) swap(a, b);
	if (a != b) {
		p[a] = b;
		sz[b] += sz[a];
	}
}

void make_set(int n) {
	p.resize(n); sz.resize(n);
	for (int i = 0; i < n; i++) {
		p[i] = i; sz[i] = 1;
	}
}



int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<pair<ll, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	make_set(n);
	vector<pair<ll, pair<int, int>>> ed(m);
	for (int i = 0; i < m; i++) {
		cin >> ed[i].second.first >> ed[i].second.second >> ed[i].first;
		ed[i].second.first--;
		ed[i].second.second--;
	}
	sort(ed.begin(), ed.end());
	int cur1 = 1;
	int cur2 = 0;
	ll ans = 0;
	while (cur1 < n) {
		//cout << cur1 << endl;
		while (cur1 < n && get_par(a[0].second) == get_par(a[cur1].second)) cur1++;
		if (cur1 >= n) break;
		while (cur2 < m && get_par(ed[cur2].second.first) == get_par(ed[cur2].second.second)) cur2++;
		if (cur2 >= m || ed[cur2].first > (a[0].first + a[cur1].first)) {
			ans += a[0].first + a[cur1].first;
			merge(a[0].second, a[cur1].second);
		}
		else {
			ans += ed[cur2].first;
			merge(ed[cur2].second.first, ed[cur2].second.second);
		}
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}