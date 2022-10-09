#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;

int cifre[30];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	if (m == 1) {
		cout << "Second\n";
		return 0;
	}

	int a=0, b=0;
	for (int _=0; _<n; _++) {
		string s;
		cin >> s;

		if (count(s.begin(), s.end(), 'G') == 2) {
			if (m > 2)
				a++;
			continue;
		}

		if (count(s.begin(), s.end(), 'R') == 2) {
			if (m > 2)
				b++;
			continue;
		}

		int i = s.find('G');
		int j = s.find('R');
		if (i == -1 && j == -1)
			continue;
		else if (i == -1)
			b++;
		else if (j == -1)
			a++;
		else {
			for (int k=0; k<30; k++)
				cifre[k] += ((abs(i-j)-1) >> k) & 1;
		}
	}

	if (a && b)
		cout << "Draw\n";
	else if (a)
		cout << "First\n";
	else if (b)
		cout << "Second\n";
	else {
		int z = 0;
		for (int i=0; i<30; i++) {
			cerr << cifre[i] << ' ';
			if (cifre[i] % (k+1))
				z++;
		}
		cerr << '\n';
		if (!z)
			cout << "Second\n";
		else
			cout << "First\n";
	}
}