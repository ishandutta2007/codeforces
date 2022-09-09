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
string s[50];
const int INF = 1000000000;

map<vector<pair<int, int>>, int> dp;

int cnt (vector<pair<int, int>> state) {
	if (dp.find(state) != dp.end())
		return dp[state];
	int w = (state[0].first + state[0].second) & 1;
	if (state.size() == 1 && state[0].first == n - 1 && state[0].second == n - 1) {
		if (!w) {
			if (s[n - 1][n - 1] == 'a')
				return 1;
			else
				if (s[n - 1][n - 1] == 'b')
					return -1;
		}
		else {
			if (s[n - 1][n - 1] == 'a')
				return -1;
			else
				if (s[n - 1][n - 1] == 'b')
					return 1;
		}
		return 0;
	}
	char cur = s[state[0].first][state[0].second];
	if (!w) {
		int res = 0;
		if (cur == 'a')
			++res;
		if (cur == 'b')
			--res;

		vector<pair<int, int>> go[30];

		for (int i = 0; i < state.size(); ++i) {
			if (state[i].first < n - 1)
				go[s[state[i].first + 1][state[i].second] - 'a'].push_back(mp(state[i].first + 1, state[i].second));
			if (state[i].second < n - 1)
				go[s[state[i].first][state[i].second + 1] - 'a'].push_back(mp(state[i].first, state[i].second + 1));
		}

		int add = -INF;
		for (char c = 'a'; c <= 'z'; ++c) {
			if (go[c - 'a'].size() > 0) {
				sort(all(go[c - 'a']));
				go[c - 'a'].resize(unique(all(go[c - 'a'])) - go[c - 'a'].begin());
				add = max(add, cnt(go[c - 'a']));
			}
		}
		res -= add;
		return dp[state] = res;
	}
	else {
		int res = 0;
		if (cur == 'b')
			++res;
		if (cur == 'a')
			--res;
		vector<pair<int, int>> go[30];

		for (int i = 0; i < state.size(); ++i) {
			if (state[i].first < n - 1)
				go[s[state[i].first + 1][state[i].second] - 'a'].push_back(mp(state[i].first + 1, state[i].second));
			if (state[i].second < n - 1)
				go[s[state[i].first][state[i].second + 1] - 'a'].push_back(mp(state[i].first, state[i].second + 1));
		}

		int add = -INF;
		for (char c = 'a'; c <= 'z'; ++c) {
			if (go[c - 'a'].size() > 0) {
				sort(all(go[c - 'a']));
				go[c - 'a'].resize(unique(all(go[c - 'a'])) - go[c - 'a'].begin());
				add = max(add, cnt(go[c - 'a']));
			}
		}
		res -= add;
		return dp[state] = res;
	}

}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	vector<pair<int, int>> start(1, mp(0,0));
	int res = cnt(start);
	
	if (res > 0)
		cout << "FIRST\n";
	if (res < 0)
		cout << "SECOND\n";
	if (res == 0)
		cout << "DRAW\n";

}