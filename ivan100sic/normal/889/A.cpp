#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int rm[200005];
int vr[200005];

set<int> dostupni;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	dostupni.insert(0);
	int sol = 1;

	for (int i=1; i<=n; i++) {
		int x = a[i];
		if (dostupni.count(x)) {
			dostupni.erase(x);
			dostupni.insert(i);
		} else {
			dostupni.insert(i);
			sol++;
		}
	}

	cout << sol << '\n';

}