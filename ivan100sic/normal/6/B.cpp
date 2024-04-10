#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

string a[105];
int n, m;
char prec;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	string s;
	cin >> n >> m >> s;
	prec = s[0];

	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] = string(".") + a[i] + string(".");
	}
	a[0] = a[n+1] = string(m+2, '.');

	cerr << a[0] << '\n';

	set<char> kol;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (a[i][j] == prec) {
				kol.insert(a[i][j+1]);
				kol.insert(a[i][j-1]);
				kol.insert(a[i-1][j]);
				kol.insert(a[i+1][j]);
			}
		}
	}

	kol.erase(prec);
	kol.erase('.');

	cout << kol.size();
}