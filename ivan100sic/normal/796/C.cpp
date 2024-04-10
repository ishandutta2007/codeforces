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

int n;
int a[300005];

vector<int> e[300005];

const int MAXN = 1 << 19;

struct tree {
	int a[2*MAXN];

	void write(int pos, int val) {
		pos += MAXN - 1;
		a[pos] = val;
		while (pos > 1) {
			pos /= 2;
			a[pos] = max(a[2*pos], a[2*pos+1]);
		}
	}

	int daj() {
		return a[1];
	}

	tree() {
		for (int i=0; i<2*MAXN; i++) {
			a[i] = -2'000'000'000;
		}
	}
} drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i=1; i<=n; i++) {
		drvo.write(i, a[i]+2);
	}

	int sol = 2e9;

	for (int x=1; x<=n; x++) {
		
		drvo.write(x, a[x]);
		for (int y : e[x]) {
			drvo.write(y, a[y]+1);
		}

		sol = min(sol, drvo.daj());

		drvo.write(x, a[x]+2);
		for (int y : e[x]) {
			drvo.write(y, a[y]+2);
		}
	}

	cout << sol;



}