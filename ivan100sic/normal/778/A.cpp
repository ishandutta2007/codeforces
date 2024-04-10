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

int n, m;
string s, p;
int a[200005];

string elim(int k) {
	string x = s;
	for (int i=0; i<k; i++) {
		x[a[i]] = '.';
	}
	int j = 0;
	for (int i=0; i<n; i++) {
		if (x[i] != '.') {
			x[j++] = x[i];
		}
	}
	x.resize(n-k);

	// cerr << s << ' ' << k << ' ' << x << '\n';
	
	return x;
}

bool moze(string q) {
	int j = 0;
	for (int i=0; i<q.size(); i++) {
		if (j < p.size() && q[i] == p[j]) {
			j++;
		}
	}

	// cerr << j  << ' ' << p.size() << '\n';

	return j == p.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> p;
	n = s.size();
	m = p.size();

	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i]--;
	}

	int l=1, r=n, o=0;

	while (l <= r) {
		int m = (l+r) / 2;
		string q = elim(m);
		if (moze(q)) {
			l = m+1;
			o = m;
		} else {
			r = m-1;
		}
	}

	cout << o;
}