#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <queue>
using namespace std;

struct node {
	node* next[26];
	node* link;
};

int nid;
node pool[1100005];

void insert(node* root, string s) {
	for (char x : s) {
		if (root->next[x - 'a']  == nullptr) {
			root = root->next[x - 'a'] = pool + nid;
			nid++;
		} else {
			root = root->next[x - 'a'];
		}
	}
}

vector<int> e[1100005];
int dp[1100005][2];
bool start[1100005];

void dfs(int x) {
	dp[x][0] = 0;
	dp[x][1] = 1;
	for (int y : e[x]) {
		dfs(y);
		dp[x][0] += max(dp[y][0], dp[y][1]);
		dp[x][1] += dp[y][0];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		nid = 1;
		int n;
		cin >> n;

		vector<string> vs;

		int gomno = 2;

		while (n--) {
			string s;
			cin >> s;
			vs.push_back(s);
			gomno += s.size();
		}

		memset(pool, 0, sizeof(node) * gomno);

		for (string s : vs) {
			insert(pool, s);
		}

		queue<node*> q;
		pool->link = nullptr;
		for (int i=0; i<26; i++) {
			if (pool->next[i]) {
				pool->next[i]->link = pool;
				q.push(pool->next[i]);
			}
		}

		while (!q.empty()) {
			node* t = q.front(); q.pop();
			if (t == nullptr) {
				continue;
			}
			for (int i=0; i<26; i++) {
				if (t->next[i] && t->link) {
					t->next[i]->link = t->link->next[i];
					q.push(t->next[i]);
				}
			}
		}

		for (int i=0; i<nid; i++) {
			e[i].clear();
		}

		for (int i=0; i<nid; i++) {
			start[i] = true;
		}

		for (int i=0; i<nid; i++) {
			if (pool[i].link) {
				int u = pool[i].link - pool;
				int v = i;
				// cerr << u << ' ' << v << '\n';
				e[u].push_back(v);
				start[v] = false;
			}
		}

		int sol = 0;

		// cerr << nid << '\n';

		for (int i=0; i<nid; i++) {
			if (start[i]) {
				// cerr << "krecem " << i << '\n';
				dfs(i);
				if (i == 0) {
					sol += dp[i][0];
				} else {
					sol += max(dp[i][0], dp[i][1]);
				}
				// cerr << "sol: " << sol << '\n';
			}
		}

		cout << sol << '\n';
	}
}