#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int c[200005];
int last[200005];

set<int> nula;

bool uzeto[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		c[a[i]]++;
		last[a[i]] = i;
	}

	for (int i=1; i<=n; i++) {
		if (c[i] == 0) {
			nula.insert(i);
		}
	}

	int ch = 0;

	for (int i=1; i<=n; i++) {
		if (c[a[i]] > 1) {
			if (uzeto[a[i]]) {
				a[i] = *nula.begin();
				nula.erase(nula.begin());
				ch++;
			} else {
				// uzimam a[i] samo ako je nula veca od a[i] ili nemam vise izbora
				if (*nula.begin() > a[i] || last[a[i]] == i) {
					//
					uzeto[a[i]] = true;
				} else {
					a[i] = *nula.begin();
					nula.erase(nula.begin());
					ch++;
				}
			}
		}
	}

	cout << ch << '\n';

	for (int i=1; i<=n; i++) {
		cout << a[i] << ' ';
	}


}