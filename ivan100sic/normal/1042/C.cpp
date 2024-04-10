#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[200005], n;
vector<int> nule, neg, pos;

void stampaj(vector<int> v) { // v brisem (moze prazno)
	if (v.size()) {
		for (int i=1; i<(int)v.size(); i++)
			cout << "1 " << v[i] << ' ' << v[0] << '\n';
		cout << "2 " << v[0] << '\n';
	}

	vector<int> ostalo(n+1, 1);
	for (int x : v)
		ostalo[x] = 0;

	int oo = 1;
	while (ostalo[oo] == 0)
		oo++;

	ostalo[oo] = 0;

	for (int i=1; i<=n; i++)
		if (ostalo[i])
			cout << "1 " << i << ' ' << oo << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a[i] = x;
		if (x == 0)
			nule.push_back(i);
		else if (x > 0)
			pos.push_back(i);
		else
			neg.push_back(i);
	}

	// da li mogu da napravim pozitivan proizvod?
	bool mposprod = pos.size() > 0 || neg.size() > 1;
	if (mposprod) {
		// izbaci sve nule i najmanji (po abs) negativan broj
		auto v = nule;
		if (neg.size() % 2 == 1) {
			int j = neg[0];
			for (int i : neg)
				if (a[i] > a[j])
					j = i;
			v.push_back(j);
		}
		stampaj(v);
		return 0;
	}

	// da li mogu da napravim nula?
	bool mnula = nule.size() > 0;
	if (mnula) {
		stampaj({});
	}

	// mora negativan. ne radi nista (nemoguce)
	
}