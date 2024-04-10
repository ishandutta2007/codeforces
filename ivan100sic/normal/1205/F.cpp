#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> razuzdana(int n) {
	if (n == 1)
		return {0};
	vector<int> a;
	for (int i=0; i<n/2; i++) {
		a.push_back(n/2+i);
		a.push_back(i);
	}
	if (n % 2) {
		a.insert(a.begin()+1, n-1);
	}
	reverse(a.begin(), a.end());
	return a;
}

struct hop {
	unsigned k : 16;
	unsigned x : 8;
	unsigned mv : 2;
};

hop d[101][5052][101];

void dp() {
	memset(d, 0x55, sizeof(d));

	d[1][1][1] = {0, 0, 0};
	d[2][3][2] = {1, 1, 1};
	d[2][3][0] = {1, 1, 3};
	d[3][5][0] = {0, 0, 0};
	d[3][6][3] = {3, 2, 1};

	for (int n=4; n<=100; n++) {
		auto v = razuzdana(n);
		d[n][n+1][0] = {0, 0, 0};
	}

	for (unsigned n=3; n<100; n++) {
		for (unsigned k=n+1; k<=n*(n+1)/2; k++) {
			for (unsigned x=0; x<=n; x++) {
				if (d[n][k][x].k == 0x5555)
					continue;
				// produzi sufiks
				d[n+1][k+x+2-(x==n)][x+1] = {k, x, 1};
				// zapocni novi sufiks
				d[n+1][k+2][1] = {k, x, 3};
			}
		}
	}
}

vector<int> rek(int n, int k, int x) {
	if (d[n][k][x].mv == 0)
		return razuzdana(n);
	else if (d[n][k][x].mv == 1) {
		auto v = rek(n-1, d[n][k][x].k, d[n][k][x].x);
		v.push_back(n-1);
		return v;
	} else {
		auto v = rek(n-1, d[n][k][x].k, d[n][k][x].x);
		for (int& x : v)
			x = n-2-x;
		v.push_back(n-1);
		return v;
	}
}

void resi(int n, int k) {
	for (int x=0; x<=n; x++) {
		if (d[n][k][x].k != 0x5555) {
			cout << "YES\n";
			auto a = rek(n, k, x);
			for (int x : a) {
				cout << x+1 << ' ';
			}
			cout << '\n';
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	dp();
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		resi(n, k);
	}

}