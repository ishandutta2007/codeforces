#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int H = 30;

int a[1005][1005], racva[H+3], kraj[H+3];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int k;
	cin >> k;

	// napravi glavni lanac
	racva[0] = n++;
	int cilj = n++;
	for (int i=1; i<H; i++) {
		racva[i] = n++;
		int x = n++;
		int y = n++;
		a[racva[i]][x] = 1;
		a[racva[i]][y] = 1;
		a[racva[i-1]][x] = 1;
		a[racva[i-1]][y] = 1;
	}

	// napravi side-lance
	for (int i=0; i<H; i++) {
		int duzina = 2*(H-1-i);
		kraj[i] = racva[i];
		while (duzina--) {
			int tmp = n++;
			a[tmp][kraj[i]] = 1;
			kraj[i] = tmp;
		}
	}

	// napravi ciljni cvor
	for (int i=0; i<H; i++)
		if (k & (1 << i))
			a[kraj[i]][cilj] = 1;

	cout << n << '\n';
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (a[i][j] || a[j][i])
				cout << 'Y';
			else
				cout << 'N';
		}
		cout << '\n';
	}

}