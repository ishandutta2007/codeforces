#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
//#define FILENAME "1dembedding"
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
void solve();
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
#else
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	//cin >> t;
    while (t--)
        solve();
    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

int n;
int type[100500], a[100500];
int deg[100500];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> type[i];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		if (a[i] >= 0)
			++deg[a[i]];
	}

	vector<int> best;

	for (int i = 0; i < n; ++i)
		if (type[i] == 1) {
			vector<int> now;
			now.push_back(i);
			int cur = i;
			while (a[cur] != -1 && deg[a[cur]] == 1) {
				now.push_back(a[cur]);
				cur = a[cur];
			}
			if (best.size() < now.size())
				best = now;
		}
	cout << best.size() << endl;
	for (int i = best.size() - 1; i >= 0; --i)
		cout << best[i] + 1 << ' ';
}