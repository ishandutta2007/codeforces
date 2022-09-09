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
#ifdef room210
	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

//#define int li

int n, m;
int know[200][200];

int dsu[200];
int find_set (int v)  {
	if (dsu[v] == v)
		return v;
	return dsu[v] = find_set(dsu[v]);
}

bool merge(int q, int w) {
	q = find_set(q);
	w = find_set(w);
	if (q == w)
		return false;
	if (rand() & 1)
		dsu[q] = w;
	else
		dsu[w] = q;
	return true;
}

void solve(){
	cin >> n >> m;
	int g = 0;
	for (int i = 0; i < n; ++i) {
		int num; cin >> num;
		g += num;
		while (num--) {
			int q;
			cin >> q;
			--q;
			know[i][q] = 1;
		}
	}
	if (g == 0) {
		cout << n;
		return;
	}
	for (int i = 0; i < n; ++i)
		dsu[i] = i;
	int ans = n - 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if (i != j) {
				for (int k = 0; k < m; ++k)
					if (know[i][k] && know[j][k]) {
						if (merge(i, j))
							--ans;
					}
			}
	}
	cout << ans;
}