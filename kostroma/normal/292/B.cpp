#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();
//void precalc();

#define FILENAME "change me please"
int main(){
	string s = FILENAME;
#ifdef room210
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	//cout.sync_with_stdio(0);
	int t = 1;
	//precalc();
	//cout << "done!\n";
	//cin >> t;
	//gen();
	while (t--)
		solve();
	/*
#ifdef room210
	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif*/
	return 0;
}

//#define int li

int n, m;
vector <int> g[100500];

bool used[100500];
int num = 0;
void dfs (int v) {
	if (used[v])
		return;
	used[v] = true;
	++num;
	for (int i = 0; i < g[v].size(); ++i)
		dfs(g[v][i]);
}

void solve () {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	if (num != n) {
		cout << "unknown topology";
		return;
	}
	int mn = 1000000000, mx = 0;
	for (int i = 0; i < n; ++i) {
		mn = min(mn, (int)g[i].size());
		mx = max(mx, (int)g[i].size());
	}
	if (mn == 2 && mx == 2) {
		cout << "ring topology";
		return;
	}
	if (mn == 1) {
		int cnt2 = 0, cnt1 = 0;
		for (int i = 0; i < n; ++i) {
			if (g[i].size() == 2)
				++cnt2;
			if (g[i].size() == 1)
				++cnt1;
		}
		if (cnt1 == 2 && cnt2 == n - 2) {
			cout << "bus topology";
			return;
		}
		if (cnt1 == n - 1 && mx == n - 1) {
			cout << "star topology";
			return;
		}
	}
	cout << "unknown topology";
}