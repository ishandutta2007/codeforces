// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
string s;
int b[1000005];
int nx[1000005];
basic_string<int> e[1000005];

int gn(int x) {
	if (x != nx[x]) {
		return nx[x] = gn(nx[x]);
	} else {
		return x;
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> s;
	int p0 = -1, p1 = -1;
	for (int i=0; i<n; i++) {
		int& x = b[i+1];
		if (s[i] == '?') {
			x = i - min(p0, p1);
		} else if (s[i] == '0') {
			x = i - p1;
			p0 = i;
		} else {
			x = i - p0;
			p1 = i;
		}
	}

	for (int i=0; i<=n; i++) {
		nx[i] = i;
		e[b[i]] += i;
	}
	nx[n+1] = n+1;

	for (int g=1; g<=n; g++) {
		int z = 0, p = 0;
		while (1) {
			// pomeri ga za bar g
			int t = gn(min(n+1, p+g));
			if (t <= n) {
				z++;
				p = t;
			} else {
				break;
			}
		}

		cout << z << " \n"[g == n];

		for (int j : e[g]) {
			nx[j] = nx[j+1];
		}
	}
}