#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, a, b;
set<int> p;
map<int, int> v;
map<int, int> orig_idx;

int sol[100005];
basic_string<int> cc;
int list_tip;

void dfs(int x) {
	cc += x;
	v[x] = 1;

	int sus_c = 0, tip_suseda = 0;

	for (int y : {a-x, b-x}) {
		if (y != x && p.count(y)) {
			sus_c++;
			if (y == a-x)
				tip_suseda = 0;
			else
				tip_suseda = 1;
			if (!v[y])
				dfs(y);
		}
	}

	if (sus_c == 1) {
		list_tip = tip_suseda;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		p.insert(x);
		orig_idx[x] = i;
	}

	for (int x : p) {
		if (!v[x]) {
			cc = {};
			dfs(x);
			if (cc.size() % 2) {
				// daj mu sansu, probaj da nadjes cvor koji ima loop
				// on je inace sigurno list
				int ok = 0;
				for (int x : cc) {
					if (x+x == a) {
						for (int y : cc)
							sol[orig_idx[y]] = 0;
						sol[orig_idx[x]] = 0;
						ok = 1;
						break;
					} else if (x+x == b) {
						for (int y : cc)
							sol[orig_idx[y]] = 1;
						sol[orig_idx[x]] = 1;
						ok = 1;
						break;
					}
				}

				if (!ok) {
					cout << "NO\n";
					return 0;
				}

			} else {
				for (int x : cc) {
					sol[orig_idx[x]] = list_tip;
				}
			}
				
		}
	}

	cout << "YES\n";
	for (int i=0; i<n; i++)
		cout << sol[i] << ' ';
	cout << '\n';
}