#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int m, k, n, s;
int a[500005];
int f[500005], fp;

void addf(int x) {
	if (++f[x] == 1)
		fp++;
}

void remf(int x) {
	if (--f[x] == 0)
		fp--;
}

void proveri(int l, int r) {
	int cnt = l/k + 1 + (m-r)/k;
	// cerr << "proveravam " << l << ' ' << r << ' ' << cnt << '\n';
	if (cnt < n)
		return;
	for (int i=l; i<r; i++)
		addf(a[i]);
	vector<bool> deletos(m, true);
	// uzmi prvih l/k*k
	for (int i=0; i<l/k*k; i++)
		deletos[i] = false;
	// uzmi poslednjih nzm ni ja koliko
	int broj = n*k - l/k*k - k;
	for (int i=r; i<r+broj; i++)
		deletos[i] = false;

	// uzmi ove iz sredine sto treba
	int sredina_visak = k-s;
	for (int i=l; i<r; i++)
		if (f[a[i]] > 0) {
			f[a[i]]--;
			deletos[i] = false;
		} else if (sredina_visak) {
			sredina_visak--;
			deletos[i] = false;
		}

	cout << count(deletos.begin(), deletos.end(), true) << '\n';
	for (int i=0; i<m; i++)
		if (deletos[i])
			cout << i+1 << ' ';
	cout << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> m >> k >> n >> s;
	for (int i=0; i<m; i++)
		cin >> a[i];
	for (int i=0; i<s; i++) {
		int x;
		cin >> x;
		addf(x);
	}

	{
		int r=0;
		for (int l=0; l<m; l++) {
			while (r < m && (fp > 0 || r-l < k))
				remf(a[r++]);
			if (fp == 0 && r-l >= k)
				proveri(l, r);
			addf(a[l]);
		}
	}

	cout << "-1\n";
}