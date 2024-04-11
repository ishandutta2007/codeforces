#include <bits/stdc++.h>

using namespace std;

const int maxw = 5e6;

map<char, int> go[maxw];
pair<int, int> ans[maxw];
int last = 0;

void add(const string &s, int st) {
	int n = s.size();
	int node = 0;
	for (int i = st; i < n; i++) {
		int c = s[i];
		if (!go[node][c]) {
			last++;
			go[node][c] = last;
			ans[last] = {st + 1, i + 1};
		}
		node = go[node][c];
	}
	node = 0;
	for (int i = n - st - 1; i >= 0; i--) {
		char c = s[i];
		if (!go[node][c]) {
			last++;
			go[node][c] = last;
			ans[last] = {n - st, i + 1};
		}
		node = go[node][c];
	}
}

pair<int, int> find(const string &s, int st) {
	int n = s.size();
	int node = 0;
	for (int i = st; i < n; i++) {
		char c = s[i];
		if (!go[node][c]) {
			if (node == 0) return {-1, -1};
			return ans[node];
		}
		node = go[node][c];
	}
	return ans[node];
}

int main() {
	string s, t;
	cin >> s >> t;
	
	int n = s.size(), m = t.size();
	for (int i = 0; i < n; i++) {
		add(s, i);
	}
	
	vector< pair<int, int> > result;
	for (int i = 0; i < m;) {
		auto p = find(t, i);
		if (p.first == -1) {
			cout << -1 << '\n';
			return 0;
		}
		result.push_back(p);
		i += abs(p.first - p.second) + 1;
	}
	
	cout << result.size() << '\n';
	for (auto i: result) {
		cout << i.first << ' ' << i.second << '\n';
	}
}