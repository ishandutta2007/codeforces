#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

vector<int> b[100005];

void gusto() {
	int pl = 0, ph = 0, l=0, h=0;
	int c = 0;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<a[i]; j++) {
			cout << pl << ' ';
			c++;
			if (j == 0) {
				l = c;
			}
			h = c;
		}
		pl = l;
		ph = h;
	}
	cout << '\n';
}

void retko() {
	int pl = 0, ph = 0, l=0, h=0;
	int c = 0;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<a[i]; j++) {
			cout << (j ? ph : pl) << ' ';
			c++;
			if (j == 0) {
				l = c;
			}
			h = c;
		}
		pl = l;
		ph = h;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<=n; i++) {
		cin >> a[i];
	}

	bool perfect = true;

	for (int i=1; i<=n; i++) {
		if (a[i] > 1 && a[i-1] > 1) {
			perfect = false;
		}
	}

	if (perfect) {
		cout << "perfect\n";
		return 0;
	}

	cout << "ambiguous\n";
	gusto();
	retko();
}