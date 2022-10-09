// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int r[105], b[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> r[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	int ima = 0, lose = 0;
	for (int i=0; i<n; i++) {
		if (r[i] == 1 && b[i] == 0) {
			ima++;
		} else if (r[i] == 0 && b[i] == 1) {
			lose++;
		}
	}

	if (!ima)
		return cout << "-1\n", 0;
	else {
		int x = 1;
		while (ima * x <= lose)
			x++;
		cout << x << '\n';
	}
}

// I will still practice daily...