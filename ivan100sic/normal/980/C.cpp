#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int n, k;
int a[100005];
vector<pair<int, int>> grupe;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		// da li sam vec u nekoj grupi?
		int ima = 0;
		for (auto g : grupe) {
			if (g.first <= a[i] && a[i] <= g.second) {
				ima = 1;
				break;
			}
		}

		if (ima) {
			continue;
		}

		int rmax = -1;
		int lee = -1;
		for (auto g : grupe) {
			if (g.second < a[i]) {
				if (g.second > rmax) {
					rmax = g.second;
					lee = g.first;
				}
			}
		}

		if (lee != -1 && lee + k - 1 >= a[i]) {
			// prosiri
			for (auto& g : grupe) {
				if (g.first == lee) {
					g.second = a[i];
					break;
				}
			}
		} else {
			grupe.push_back({ max(rmax + 1, a[i] - k + 1), a[i] });
		}
	}

	for (int i = 1; i <= n; i++) {
		int ima = 0;
		for (auto g : grupe) {
			if (g.first <= a[i] && a[i] <= g.second) {
				ima = 1;
				cout << g.first << ' ';
				break;
			}
		}
	}
	cout << '\n';
}

int main() {
	solve();
	// system("pause");
}