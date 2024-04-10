#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, k;
vector<int> mejn;
vector<int> e[100005];

vector<int> v;
vector<int> state;

bool bad;

void dfs(int x) {
	state[x] = 1;
	for (int y : e[x]) {
		if (state[y] == 1) {
			bad = true;
		} else if (state[y] == 0) {
			dfs(y);
		}
	}
	state[x] = 2;
	v.push_back(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	mejn.resize(k);
	for (int& x : mejn) {
		cin >> x;
	}

	for (int i=1; i<=n; i++) {
		int z;
		cin >> z;
		e[i].resize(z);
		for (int& x : e[i]) {
			cin >> x;
		}
	}

	state = vector<int>(n+1, 0);

	for (int x : mejn) {
		if (state[x] == 0) {
			dfs(x);
		}
	}

	if (bad) {
		cout << -1;
		return 0;
	}

	cout << v.size() << '\n';
	for (int x : v) {
		cout << x << ' ';
	}
}