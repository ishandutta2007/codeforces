#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

const int MAXN = 200005;

int n;
int l[MAXN], par[MAXN];
vector <int> v[MAXN];
unordered_set <int> s[MAXN];

void dfs (int x, int rod) {
	par[x] = rod;
	for (int i=0; i<v[x].size(); i++) {
		int sus = v[x] [i];
		if (sus == rod) continue;
		dfs(sus, x);
	}
}

int main () {
	cin >> n;
	for (int i=0; i<n-1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
		s[x].insert(y);
		s[y].insert(x);
	}
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
	}
	if (l[0] != 1) {
		cout << "No";
		return 0;
	}
	dfs(1, 0);
	int ind = 1;
	for (int i=0; i<n; i++) {
		int x = l[i];
		int len = x == 1 ? v[1].size() : v[x].size() - 1;
		for (int j=ind; j<ind+len; j++) {
			if (s[x].find(l[j]) == s[x].end()) {
				cout << "No";
				return 0;
			}
		}
		ind += len;
	}
	cout << "Yes";
	return 0;
}