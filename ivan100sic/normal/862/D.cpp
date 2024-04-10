#include <bits/stdc++.h>
using namespace std;

map<string, int> cache;

int ask(string s) {
	if (cache.count(s)) {
		return cache[s];
	}

	cout << "? " << s << '\n' << flush;
	int x;
	cin >> x;
	return cache[s] = x;
}

void ans(int a, int b) {
	cout << "! " << (a+1) << ' ' << (b+1) << '\n' << flush;
	exit(0);
}

int n;
string pad;
int nula = -1, kec = -1;

void nadji(int l, int r, int sta) {
	cerr << "entering " << l << ' ' << r << '\n';

	if (sta == 2) {

		string tmp = pad;
		int m = (l+r) / 2;
		for (int i=l; i<m; i++) {
			tmp[i] = '1';
		}

		int t = ask(tmp);

		if (t == ask(pad) - (m - l)) {
			// levo su sve kecevi
			kec = l;
			nadji(m, r, 0);
		} else if (t == ask(pad) + (m - l)) {
			// levo su sve nule
			nula = l;
			nadji(m, r, 1);
		} else {
			// nastavi oba da trazis u levoj polovini
			nadji(l, m, 2);
		}
	} else if (sta == 1) {
		if (kec != -1) {
			return;
		}

		if (r == l+1) {
			kec = l;
		} else {
			nadji(l, r, 2);
		}
	} else {
		if (nula != -1) {
			return;
		}

		if (r == l+1) {
			nula = l;
		} else {
			nadji(l, r, 2);
		}
	}		
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	pad = string(n, '0');
	ask(pad);

	nadji(0, n, 2);
	ans(nula, kec);	
}