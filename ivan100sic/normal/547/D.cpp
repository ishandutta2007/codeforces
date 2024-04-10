#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int x[600005], y[600005], n, k;
char sol[600005];
set<int> ex[200005], ey[200005];

void rm(int i, char c) {
	sol[i] = c;
	ex[x[i]].erase(i);
	ey[y[i]].erase(i);
}

void walky(int i);

void walkx(int i) {
	rm(i, 'r');
	if (!ex[x[i]].size()) return;
	int j = *ex[x[i]].begin();
	walky(j);
}

void walky(int i) {
	rm(i, 'b');
	if (!ey[y[i]].size()) return;
	int j = *ey[y[i]].begin();
	walkx(j);
}

void add(int xx, int yy) {
	x[k] = xx;
	y[k] = yy;
	ex[x[k]].insert(k);
	ey[y[k]].insert(k);
	k++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
		ex[x[i]].insert(i);
		ey[y[i]].insert(i);
	}
	k = n;

	for (int i=1; i<=200000; i++) {
		if (ex[i].size() % 2)
			add(i, 0);	

		if (ey[i].size() % 2)
			add(0, i);
	}

	if (n % 2)
		add(0, 0);

	for (int x=0; x<=200000; x++) {
		while (ex[x].size()) {
			int i = *ex[x].begin();
			walkx(i);
		}
	}

	for (int i=0; i<n; i++)
		cout << sol[i];
	cout << '\n';
}