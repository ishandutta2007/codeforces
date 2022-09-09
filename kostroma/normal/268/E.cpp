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
void precalc();
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

#define int li

int n;
int l[100500], p[100500];

int id[100500];

bool cmp (int q, int w) {
	return l[q] * p[q] * (100 - p[w]) >= l[w] * p[w] * (100 - p[q]);
}

int pref[100500];

void solve(){
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> p[i];
		id[i] = i;
	}
	sort (id, id + n, cmp);
	pref[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		pref[i] = pref[i + 1] + p[id[i]];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cur = id[i];
		ans += l[cur] * (10000 + p[cur] * (100* n - 100 * i - 100 - pref[i + 1]));
	}
	printf ("%.15lf\n", ans / 10000.0);
}