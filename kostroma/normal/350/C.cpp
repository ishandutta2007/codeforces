#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
//#define FILENAME "1dembedding"
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
void solve();
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
#else
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	//cin >> t;
    while (t--)
        solve();
    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

int n;
int x[100500];
int y[100500];
int p[100500];

bool cmp (int q, int w) {
	return abs(x[q]) + abs(y[q]) < abs(x[w]) + abs(y[w]);
}

void solve() {
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		p[i] = i;
		if (x[i] != 0)
			sum += 2;
		if (y[i] != 0)
			sum += 2;
	}
	sort(p, p + n, cmp);
	sum += 2 * n;
	cout << sum << "\n";
	for (int w = 0; w < n; ++w) {
		int i = p[w];
		if (x[i] > 0)
			cout << "1 " << x[i] << " R\n";
		if (x[i] < 0)
			cout << "1 " << -x[i] << " L\n";
		if (y[i] > 0)
			cout << "1 " << y[i] << " U\n";
		if (y[i] < 0)
			cout << "1 " << -y[i] << " D\n";
		cout << "2\n";
		if (x[i] > 0)
			cout << "1 " << x[i] << " L\n";
		if (x[i] < 0)
			cout << "1 " << -x[i] << " R\n";
		if (y[i] > 0)
			cout << "1 " << y[i] << " D\n";
		if (y[i] < 0)
			cout << "1 " << -y[i] << " U\n";
		cout << "3\n";
	}
}