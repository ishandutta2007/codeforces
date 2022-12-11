#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int nmax = 1050;

int cnt[nmax];
int a[25][25];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n * n; ++i) {
		int x;
		cin >> x;
		//x = 1;
		++cnt[x];
	}

	if (n % 2 == 0) {
		for (int i = 0; i < nmax; ++i) {
			if (cnt[i] % 4) {
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
		int ptr = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (a[i][j]) {
					continue;
				}
				while (cnt[ptr] == 0) {
					++ptr;
				}
				a[i][j] = ptr;
				a[n - i + 1][j] = ptr;
				a[i][n - j + 1] = ptr;
				a[n - i + 1][n - j + 1] = ptr;
				cnt[ptr] -= 4;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		return 0;
	}

	int odd = 0;
	for (int i = 1; i < nmax; ++i) {
		if (cnt[i] & 1) {
			++odd;
		}
	}
	if (odd != 1) {
		cout << "NO\n";
		return 0;
	}

	for (int i = 1; i < nmax; ++i) {
		if (cnt[i] & 1) {
			odd = i;
		}
	}
	a[(n + 1) / 2][(n + 1) / 2] = odd;
	--cnt[odd];

	int ptr = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i][j]) {
				continue;
			}
			if (i == n - i + 1 || j == n - j + 1) {
				continue;
			}
			//cout << i << " " << j << endl;
			while (ptr < nmax && cnt[ptr] < 4) {
				++ptr;
			}
			if (ptr == nmax) {
				cout << "NO\n";
				return 0;
			}
			//cout << "!!" << ptr << endl;
			
			a[i][j] = ptr;
			a[n - i + 1][j] = ptr;
			a[i][n - j + 1] = ptr;
			a[n - i + 1][n - j + 1] = ptr;
			cnt[ptr] -= 4;
			//cout << "paint " << i << " " << j << " " << n - i + 1 << " " << j << endl;
		}
	}

	ptr = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i][j]) {
				continue;
			}
			//cout << i << " " << j << endl;
			while (cnt[ptr] < 2) {
				++ptr;
			}
			//cout << "!!" << ptr << endl;
			a[i][j] = ptr;
			a[n - i + 1][j] = ptr;
			a[i][n - j + 1] = ptr;
			a[n - i + 1][n - j + 1] = ptr;
			cnt[ptr] -= 2;
			//cout << "paint " << i << " " << j << " " << n - i + 1 << " " << j << endl;
		}
	}

	cout << "YES\n";
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	
}