#include <bits/stdc++.h>
using namespace std;

int n, m;

void nos() {
	cout << "NO\n";
	exit(0);
}

void zav(vector<vector<int>> a) {
	cout << "YES\n";
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout << a[i][j] + 1 << ' ';
		}
		cout << '\n';
	}	
	exit(0);
}

vector<int> small_transp_alt(int m) {
	// m >= 8
	vector<int> a(m, 0);

	auto nr = [&] (int minus) {
		for (int j=0; j<m-minus; j+=4) {
			int b = j;
			a[j + 0] = 2 + b;
			a[j + 1] = 0 + b;
			a[j + 2] = 3 + b;
			a[j + 3] = 1 + b;
		}
	};

	if (m % 4 == 0) {
		nr(0);
		return a;
	}

	if (m % 4 == 1) {
		nr(5);
		int b = m-5;

		a[b + 0] = b + 2;
		a[b + 1] = b + 4;
		a[b + 2] = b + 0;
		a[b + 3] = b + 3;
		a[b + 4] = b + 1;

		return a;
	}

	if (m % 4 == 2) {
		nr(6);
		int b = m-6;

		a[b + 0] = b + 2;
		a[b + 1] = b + 4;
		a[b + 2] = b + 0;
		a[b + 3] = b + 3;
		a[b + 4] = b + 1;
		a[b + 5] = b + 5;

		return a;
	}

	if (m % 4 == 3) {
		nr(7);
		int b = m-7;

		a[b + 0] = b + 2;
		a[b + 1] = b + 0;
		a[b + 2] = b + 4;
		a[b + 3] = b + 1;
		a[b + 4] = b + 6;
		a[b + 5] = b + 3;
		a[b + 6] = b + 5;

		return a;
	}

	return {};
}

vector<vector<int>> resi2(int m) {

	vector<vector<int>> a(2, vector<int>(m, 0));	

	if (m == 4) {
		a[0] = {0, 2, 4, 1};
		a[1] = {7, 5, 3, 6};
		return a;
	}

	if (m == 5) {
		a[0] = {0, 2, 4, 1, 3};
		a[1] = {6, 8, 5, 7, 9};
		return a;
	}

	if (m == 6) {
		a[0] = {0, 2, 4, 1, 3, 5};
		a[1] = {7, 9, 6, 11, 8, 10};
		return a;
	}

	if (m == 7) {
		a[0] = {0, 2, 4, 1, 3, 5, 7};
		a[1] = {6, 8, 10, 12, 9, 11, 13};
		return a;
	}

	auto ss = small_transp_alt(m);

	for (int i=0; i<m; i++) {
		a[0][i] = ss[i];
		a[1][i] = ss[(i+4) % m] + m;
	}

	return a;
}

vector<vector<int>> resi1(int m) {

	vector<vector<int>> a(1, vector<int>(m, 0));

	if (m == 1) {
		return a;
	}

	if (m == 4) {
		a[0] = {2, 0, 3, 1};
		return a;
	}

	int j=0;
	for (int i=0; i<m; i+=2) {
		a[0][j++] = i;
	}
	for (int i=1; i<m; i+=2) {
		a[0][j++] = i;
	}
	return a;
}

vector<vector<int>> resi3(int m) {
	if (m == 3) {
		return {{0, 2, 3}, {4, 6, 5}, {8, 1, 7}};
	}

	if (m == 4) {
		return {{0, 2, 4, 1}, {3, 5, 11, 8}, {10, 7, 9, 6}};
	}

	vector<vector<int>> a(3, vector<int>(m, 0));

	if (m == 5) {
		a[0] = {0, 2, 4, 1, 3};
		a[1] = {6, 8, 5, 7, 9};
		a[2] = {10, 12, 14, 11, 13};

		return a;
	}

	if (m == 6) {
		a[0] = {0, 2, 4, 1, 3, 5};
		a[1] = {7, 9, 6, 8, 10, 12};
		a[2] = {11, 13, 15, 17, 14, 16};
		return a;
	}

	if (m == 7) {
		a[0] = {0, 2, 4, 1, 3, 5, 7};
		a[1] = {6, 8, 10, 12, 9, 11, 13};
		a[2] = {14, 16, 18, 15, 20, 17, 19};
		return a;
	}

	auto ss = small_transp_alt(m);

	for (int i=0; i<m; i++) {
		a[0][i] = ss[i];
		a[1][i] = ss[(i+4) % m] + m;
		a[2][i] = ss[(i+8) % m] + 2*m;
	}

	return a;
}

vector<vector<int>> primeni(vector<int> r, vector<int> c) {

	vector<vector<int>> a(n, vector<int>(m, 0));

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			a[i][j] = c[j] + m*r[i];
		}
	}

	return a;
}

vector<vector<int>> resi2t() {
	vector<vector<int>> a(n, vector<int>(m, 0));

	int k = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			a[i][j] = k;
			k += 3;
			if (k >= n*m) {
				k %= 3;
				k++;
			}
		}
	}

	return a;
}

vector<vector<int>> resi3t() {
	vector<vector<int>> a(n, vector<int>(m, 0));

	int k = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			a[i][j] = k;
			k += 4;
			if (k >= n*m) {
				k %= 4;
				k++;
			}
		}
	}

	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;

	if (n == 1) {
		if (m == 2 || m == 3) {
			nos();
		}
		zav(resi1(m));
	}

	if (n == 2) {
		if (m <= 3) {
			nos();
		}
		zav(resi2(m));
	}

	if (n == 3) {
		if (m <= 2) {
			nos();
		}
		zav(resi3(m));
	}

	// n >= 4
	if (m == 1) {
		auto s = resi1(n);
		auto t = vector<vector<int>> (n, vector<int>(m, 0));
		for (int i=0; i<n; i++) {
			t[i][0] = s[0][i];
		}
		zav(t);
	}

	if (m == 2) {
		if (n == 4) {
			zav({{0, 3}, {4, 7}, {1, 2}, {5, 6}});
		}
		if (n == 5) {
			zav({{0, 3}, {4, 7}, {1, 8}, {2, 5}, {6, 9}});
		}

		zav(resi2t());
	}

	if (m == 3) {
		if (n == 4) {
			zav({{0, 2, 3}, {4, 6, 1}, {10, 5, 7}, {8, 9, 11}});
		}
		if (n == 5) {
			zav({{0, 2, 3}, {4, 6, 1}, {8, 10, 5}, {9, 14, 12}, {13, 7, 11}});
		}
		if (n == 6) {
			zav({{0, 2, 3}, {4, 6, 1}, {8, 10, 5}, {9, 14, 12}, {7, 15, 17}, {16, 11, 13}});
		}

		zav(resi3t());
	}

	// ha
	{
		auto r = resi1(n)[0];
		auto c = resi1(m)[0];
		zav(primeni(r, c));
	}


	nos();
}