#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#ifdef LOCAL
	auto& input = cin;
	auto& output = cout;
#else
	ifstream input("input.txt");
	ofstream output("output.txt");
#endif

map<pair<int, int>, vector<int>> orig_edges;
multiset<int> e[10005];
multiset<int> eo[10005];
basic_string<int> cc, odd, q;
vector<basic_string<int>> cvorovi;
bool vis[10005];
int m;
const int n = 10000;

void no() {
	output << "-1\n";
	exit(0);
}

list<int> euler(int x) {
	list<int> a = {x};

	if (e[x].size() == 0)
		return a;

	while (e[x].size()) {
		int y = *e[x].begin();
		a.push_back(y);
		e[x].erase(e[x].find(y));
		e[y].erase(e[y].find(x));
		x = y;
	}

	for (auto it = a.begin(); it != a.end(); ++it) {
		auto l = euler(*it);
		l.pop_front();
		a.splice(next(it), l);
	}

	return a;
}

int edge(int x, int y) {
	auto& ref = orig_edges[{min(x, y), max(x, y)}];
	int z = ref.back();
	ref.pop_back();
	return z;
}

basic_string<int> edge_path(basic_string<int> b) {
	basic_string<int> a;
	for (int i=1; i<(int)b.size(); i++)
		a += edge(b[i-1], b[i]);
	return a;
}

basic_string<int> tobs(list<int> a) {
	return basic_string<int>(a.begin(), a.end());
}

void izbaci_granu(basic_string<int>& sol, int x1, int y1) {
	sol.pop_back();
	for (auto it = sol.begin(); next(it) != sol.end(); ++it) {
		int x2 = *it;
		int y2 = *next(it);
		if (min(x1, y1) == min(x2, y2) && max(x1, y1) == max(x2, y2)) {
			rotate(sol.begin(), next(it), sol.end());
			return;
		}
	}
}

void resi1(basic_string<int> a) {
	// 0 ili 2 neparna
	basic_string<int> odd, sol;
	for (int x : a)
		if (eo[x].size() % 2)
			odd += x;

	if (odd.size() == 0) {
		sol = tobs(euler(a[0]));
	} else {
		int x1 = odd[0];
		int y1 = odd[1];

		e[x1].insert(y1);
		e[y1].insert(x1);
		sol = tobs(euler(a[0]));
		izbaci_granu(sol, x1, y1);
	}

	sol = edge_path(sol);
	output << sol.size() << '\n';
	for (int x : sol)
		output << x << ' ';
	output << '\n';
}

void resi4(basic_string<int> a) {
	// 0 ili 2 neparna
	basic_string<int> odd, sol, sol1, sol2;
	for (int x : a)
		if (eo[x].size() % 2)
			odd += x;

	
	int x1 = odd[0];
	int y1 = odd[1];

	int x2 = odd[2];
	int y2 = odd[3];

	e[x1].insert(y1);
	e[y1].insert(x1);

	e[x2].insert(y2);
	e[y2].insert(x2);

	sol = tobs(euler(a[0]));
	izbaci_granu(sol, x1, y1);

	for (auto it = sol.begin(); next(it) != sol.end(); ++it) {
		int x3 = *it;
		int y3 = *next(it);
		if (min(x2, y2) == min(x3, y3) && max(x2, y2) == max(x3, y3)) {
			sol1 = basic_string<int>(sol.begin(), next(it));
			sol2 = basic_string<int>(next(it), sol.end());
			break;
		}
	}

	sol1 = edge_path(sol1);
	output << sol1.size() << '\n';
	for (int x : sol1)
		output << x << ' ';
	output << '\n';

	sol2 = edge_path(sol2);
	output << sol2.size() << '\n';
	for (int x : sol2)
		output << x << ' ';
	output << '\n';
}

void resi_sek(basic_string<int> a) {
	// 0 ili 2 neparna
	basic_string<int> odd, sol;
	for (int x : a)
		if (eo[x].size() % 2)
			odd += x;

	if (odd.size() == 0) {
		sol = tobs(euler(a[0]));
	} else {
		int x1 = odd[0];
		int y1 = odd[1];

		e[x1].insert(y1);
		e[y1].insert(x1);
		sol = tobs(euler(a[0]));
		izbaci_granu(sol, x1, y1);
	}

	sol = edge_path(sol);
	int zadnji = sol.back();
	sol.pop_back();

	output << sol.size() << '\n';
	for (int x : sol)
		output << x << ' ';
	output << '\n';
	output << "1\n" << zadnji << '\n';
}

int main() {
	input >> m;

	if (m == 1)
		no();

	for (int i=1; i<=m; i++) {
		int x, y;
		input >> x >> y;
		e[x].insert(y);
		e[y].insert(x);
		orig_edges[{min(x, y), max(x,y)}].push_back(i);
	}

	for (int i=1; i<=n; i++)
		eo[i] = e[i];

	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			q = {i};
			size_t qs = 0;
			while (qs != q.size()) {
				int x = q[qs++];
				for (int y : e[x]) {
					if (!vis[y]) {
						vis[y] = true;
						q += y;
					}
				}
			}
			if (qs == 1)
				continue;
			int z = 0;
			for (int x : q)
				z += e[x].size() % 2;
			cc += qs;
			odd += z;
			cvorovi.push_back(q);
		}
	}

	if (cc.size() > 2)
		no();
	
	if (cc.size() == 2) {
		if (odd[0] > 2 || odd[1] > 2)
			no();
		resi1(cvorovi[0]); // samo nadji jedan put
		resi1(cvorovi[1]);
	} else {
		if (odd[0] > 4)
			no();
		else if (odd[0] == 4)
			resi4(cvorovi[0]); // resi sa 4 neparna
		else
			resi_sek(cvorovi[0]); // nadji jedan put pa ga iseci negde
	}
}