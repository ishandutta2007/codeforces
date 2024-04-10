#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, set<int>> stvar;

struct tri {
	int x, y, z;
};

int n, m;
stvar a[100005];
int t[100005];

bool cmp(stvar a, stvar b) {
	return a.second.size() < b.second.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	int z = 0;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		while (x--) {
			int y;
			cin >> y;
			a[i].second.insert(y);
			z++;
		}
		a[i].first = i;
	}

	sort(a+1, a+n+1, cmp);

	for (int i=1; i<=n; i++) {
		t[i] = z/n;
	}
	for (int i=1; i<=z%n; i++)
		t[n+1-i]++;

	basic_string<int> poz, neg;
	for (int i=1; i<=n; i++) {
		int raz = (int)a[i].second.size() - t[i];
		if (raz > 0) {
			poz += i;
		} else if (raz < 0) {
			neg += i;
		}
	}

	basic_string<tri> sol;

	int i = 0, j = 0;
	while (i < (int)poz.size() && j < (int)neg.size()) {
		int ii = neg[j];
		int jj = poz[i];

		int rupa = t[ii] - (int)a[ii].second.size();
		int visak = (int)a[jj].second.size() - t[jj];

		// cerr << rupa << ' ' << visak << '\n';

		int selim = min(rupa, visak);

		if (rupa < visak) {
			// O(prvi)
			basic_string<int> vrati;
			for (int x : a[ii].second) {
				if (a[jj].second.count(x)) {
					a[jj].second.erase(x);
					vrati += x;
				}
			}
			while (selim) {
				int x = *a[jj].second.begin();
				a[jj].second.erase(x);
				a[ii].second.insert(x);
				selim--;
				sol += {a[jj].first, a[ii].first, x};
			}
			for (int x : vrati) {
				a[jj].second.insert(x);
			}
			j++;
		} else {
			// O(drugi)
			vector<int> tmp(a[jj].second.begin(), a[jj].second.end());
			for (int x : tmp) {
				if (!a[ii].second.count(x) && selim > 0) {
					selim--;
					a[jj].second.erase(x);
					a[ii].second.insert(x);
					sol += {a[jj].first, a[ii].first, x};
				}
			}
			i++;
		}
	}

	// reverse(sol.begin(), sol.end());

	cout << sol.size() << '\n';
	for (auto p : sol) {
		cout << p.x << ' ' << p.y << ' ' << p.z << '\n';
	}
}