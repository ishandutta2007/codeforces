// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

string rd() {
	string s;
	cin >> s;
	return s;
}

int find_heaviest(int l, int r) {
	if (l == r)
		return l;
	if ((r-l+1) % 2)
		r--;

	int s = (r-l+1) / 2;
	int m = (l+r) / 2;
	cout << "? " << s << ' ' << s << '\n';
	for (int i=0; i<s; i++)
		cout << l+i << " \n"[i == s-1];
	for (int i=0; i<s; i++)
		cout << l+s+i << " \n"[i == s-1];
	cout << flush;

	auto ss = rd();
	if (ss == "FIRST") {
		return find_heaviest(l, m);
	} else if (ss == "SECOND") {
		return find_heaviest(m+1, r);
	} else {
		return find_heaviest(l, m);
	}
}

void solve(vector<int> candidates, vector<int> heavy) {
	if (candidates.size() == 1) {
		cout << "! " << candidates[0] << '\n' << flush;
		return;
	}

	int k = min(heavy.size(), candidates.size() / 2);

	cout << "? " << k << ' ' << k << '\n';
	for (int i=0; i<k; i++)
		cout << heavy[i] << " \n"[i == k-1];
	for (int i=0; i<k; i++)
		cout << candidates[i] << " \n"[i == k-1];
	cout << flush;

	auto ss = rd();
	if (ss == "EQUAL") {
		for (int i=0; i<k; i++)
			heavy.push_back(candidates[i]);
		candidates.erase(candidates.begin(), candidates.begin() + k);
		solve(candidates, heavy);
	} else {
		candidates.erase(candidates.begin() + k, candidates.end());
		solve(candidates, heavy);
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (n <= 25) {
			int h = 1;
			for (int i=2; i<=n; i++) {
				cout << "? 1 1\n" << h << '\n' << i << '\n' << flush;
				if (rd() == "SECOND") {
					h = i;
				}
			}

			for (int i=1; i<=n; i++) {
				if (i == h)
					continue;
				cout << "? 1 1\n" << h << '\n' << i << '\n' << flush;
				if (rd() == "FIRST") {
					cout << "! " << i << '\n' << flush;
					break;
				}
			}
		} else {
			int h = find_heaviest(1, n);
			vector<int> candidates, heavy = {h};
			for (int i=1; i<=n; i++) {
				if (i != h) {
					candidates.push_back(i);
				}
			}

			solve(candidates, heavy);
		}
	}
}