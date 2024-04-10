// this is my code from vjudge
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int, basic_string<int>> dodaj, izbaci;

int n, l, w;
int j = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> l >> w >> n;
	for (int i=0; i<n; i++) {
		int x, p;
		cin >> x >> p;
		dodaj[x] += p;
		izbaci[min(l, x+w)] += p;
	}
	dodaj[0] += 0;
	izbaci[min(l, w)] += 0;

	basic_string<int> pozicije;
	for (auto p : dodaj)
		pozicije += p.first;
	for (auto p : izbaci)
		pozicije += p.first;
	pozicije += l;

	sort(pozicije.begin(), pozicije.end());
	pozicije.resize(unique(pozicije.begin(), pozicije.end()) - pozicije.begin());

	multiset<int> cene;

	for (int x : dodaj[0])
		cene.insert(x);

	ll sol = 0;

	for (int i=1; i<(int)pozicije.size(); i++) {
		if (cene.size() == 0) {
			cout << "-1\n";
			return 0;
		}
		int y = pozicije[i];
		
		// cerr << y << ' ' << *cene.begin() << '\n';

		sol += *cene.begin() * 1ll * (pozicije[i] - pozicije[i-1]);
		for (int x : dodaj[y])
			cene.insert(x);
		for (int x : izbaci[y])
			cene.erase(cene.find(x));
	}

	cout << sol << '\n';
}