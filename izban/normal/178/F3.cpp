#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 2010;
const int maxt = 1001001;

struct node {
	int next[26];
	int cnt;
};

int n, k;
int sz;
node t[maxt];

void add(string s) {
	int cur = 0;
	for (int i = 0; i < (int)s.length(); i++) {
		if (t[cur].next[s[i] - 'a'] == -1) {
			t[cur].next[s[i] - 'a'] = sz;
			memset(t[sz].next, -1, sizeof(t[sz].next));
			t[sz].cnt = 0;
			sz++;
		}
		cur = t[cur].next[s[i] - 'a'];
	}
	t[cur].cnt++;
}

bool cmp(vector<int>* a, vector<int>* b) {
	return a->size() > b->size();
}

vector<int>* dfs(int v, int h = 0) {
	vector<vector<int>*> e;
	for (int i = 0; i < 26; i++) if (t[v].next[i] != -1) e.push_back(dfs(t[v].next[i], h + 1));
	
	if (t[v].cnt == 0 && e.size() == 1) return e[0];
	int s = t[v].cnt;
	for (int i = 0; i < (int)e.size(); i++) s += e[i]->size() - 1;
	vector<int>* d = new vector<int>(s + 1);

	for (int i = 1; i <= t[v].cnt; i++) {
		(*d)[i] = i * (i - 1) / 2 * h;
	}
	int cur = t[v].cnt;
	for (int i = 0; i < (int)e.size(); i++) {
		for (int j = cur; j >= 0; j--) {
			for (int k = 0; k <= (int)e[i]->size() - 1; k++) {
				(*d)[j + k] = max((*d)[j + k], (*d)[j] + (*e[i])[k] + j * k * h);
			}
		}
		cur += e[i]->size() - 1;
	}
	return d;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	
	while (cin >> n >> k) {
		sz = 1;
		memset(t[0].next, -1, sizeof(t[0].next));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			add(s);
		}
		vector<int> *d = dfs(0);
		cout << (*d)[k] << endl;
	}

    return 0;
}