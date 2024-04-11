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

int n;
int p[100500];
vector<int> g[100500];
string s[100500];
string t;
vector<int> pref;
int need;

int res = 0;

void dfs(int v) {

	assert(t.size() == pref.size());
	int len = t.size();
	t += s[v];

	//cout << v + 1 << ' ' << t << endl;

	for (int i = 0; i < s[v].size(); ++i) {
		int j = pref[len - 1 + i];
		while (j > 0 && t[j] != t[i + len])
			j = pref[j - 1];
		if (t[j] == t[i + len])
			++j;
		pref.push_back(j);
		if (j == need) {
			//cout << v + 1 << ' ' << i + 1 << endl;
			++res;
		}
	}

	/*for (int i = 0; i < pref.size(); ++i)
		cout << pref[i] << ' ';
	cout << endl;*/

	for (int i = 0; i < g[v].size(); ++i)
		dfs(g[v][i]);

	t.resize(t.size() - s[v].size());
	pref.resize(pref.size() - s[v].size());

	/*cout << v + 1 << ' ' << t << endl;
	for (int i = 0; i < pref.size(); ++i)
		cout << pref[i] << ' ';
	cout << endl;*/
}

void solve () {
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		cin >> p[i + 1];
		--p[i + 1];
		cin >> s[i + 1];
		g[p[i + 1]].push_back(i + 1);
	}
	cin >> t;
	need = t.size();
	t += '#';

	pref.resize(t.size());
	pref[0] = 0;
	for (int i = 1; i < t.size(); ++i) {
		int j = pref[i - 1];
		while (j > 0 && t[i] != t[j])
			j = pref[j - 1];
		if (t[i] == t[j])
			++j;
		pref[i] = j;
	}

	dfs(0);

	cout << res;

}