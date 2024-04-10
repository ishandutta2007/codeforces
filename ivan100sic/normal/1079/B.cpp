#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int m = s.size();

	for (int a=1; a<=5; a++) {
		for (int b=1; b<=20; b++) {
			if (a*b < m)
				continue;

			int r[5] = {0};
			for (int i=0; i<a*b-m; i++)
				r[i % a]++;
			int j = 0;
			cout << a << ' ' << b << '\n';
			for (int i=0; i<a; i++) {
				int z = b - r[i];
				cout << s.substr(j, z);
				j += z;
				cout << string(r[i], '*') << '\n';
			}
			return 0;
		}
	}

			
}