#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int aa[1005];

int ask(int i, int j, int k) {
	cout << "? " << i+1 << ' ' << j+1 << ' ' << k+1 << '\n' << flush;
	cin >> i;
	return i;
}

void ans() {
	cout << "!";
	for (int i=0; i<n; i++)
		cout << ' ' << aa[i];
	cout << '\n' << flush;
	exit(0);
}

/*
	111.. -> a + c
	11.1. -> a + d
	11..1 -> a + e
	1.11. -> a + d
	1.1.1 -> a + e
	1...1 -> a + e
	.111. -> b + d
	.11.1 -> b + e
	.1.11 -> b + e
	..111 -> c + e

	ac, ad, ae, bd, be, ce

	ac, ad, ad, (ae, ae, ae | bd), be, be, ce

	ac <= ad <= ae <= be <= ce
	         <= bd <= 

*/

/*
	a+c = najmanji
	c+e = najveci
	a+d = drugi najmanji
	b+e = drugi najveci
*/

bool proveri(int* b, ll* d) {
	for (int i=0; i<5; i++) {
		for (int j=i+1; j<5; j++) {
			for (int k=j+1; k<5; k++) {
				ll stvarno = b[(1<<i)|(1<<j)|(1<<k)];
				ll ocekivano = max({d[i], d[j], d[k]}) + min({d[i], d[j], d[k]});
				if (stvarno != ocekivano)
					return false;
			}
		}
	}
	return true;
}

void resi_pet(int x) {
	int b[32], c[10], l=0;
	for (int i=0; i<5; i++) {
		for (int j=i+1; j<5; j++) {
			for (int k=j+1; k<5; k++) {
				c[l++] = b[(1<<i)|(1<<j)|(1<<k)] = ask(x+i, x+j, x+k);
			}
		}
	}
	sort(c, c+10);

	ll ac = c[0];
	ll ad = c[1];
	ll ce = c[9];
	ll be = c[8];
	ll sred = c[3];

	// pretpostavi neki redosled
	int p[5] = {0, 1, 2, 3, 4};
	ll d[5];
	for (int _i=0; _i<120; _i++) {
		// resi sistem, vidi da li se uklapa
		// b[p[0]] <= b[p[1]] <= ...

		// prvi slucaj, srednji element je (ae)
		ll a, e;
		ll ae = sred;
		d[p[0]] = a = (ac + ae - ce) / 2;
		d[p[4]] = e = (ae + ce - ac) / 2;
		d[p[2]] = ce - e;
		d[p[3]] = ad - a;
		d[p[1]] = be - e;

		if (proveri(b, d)) {
			for (int i=0; i<5; i++)
				aa[x+i] = d[i];
			return;
		}

		// drugi slucaj, srednji element je (bd)
		ll bd = sred;
		d[p[0]] = a = (ac - ce + ad + be - bd) / 2;
		d[p[4]] = e = (-ac + ce + ad + be - bd) / 2;
		d[p[2]] = ce - e;
		d[p[3]] = ad - a;
		d[p[1]] = be - e;

		if (proveri(b, d)) {
			for (int i=0; i<5; i++)
				aa[x+i] = d[i];
			return;
		}

		next_permutation(p, p+5);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i+5<=n; i+=5) {
		resi_pet(i);
	}
	resi_pet(n-5);
	ans();
}