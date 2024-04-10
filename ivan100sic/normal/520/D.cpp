#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int x[100005], y[100005];
int n;

map<pair<int, int>, int> ptoid;
set<pair<int, int>> ima;
set<int> bris;

bool stabilan(int x, int y) {
	if (y == 0)
		return true;
	return ima.count({x+1, y-1}) || ima.count({x, y-1}) || ima.count({x-1, y-1});
}

bool obrisiv(int x, int y) {
	ima.erase({x, y});
	bool ok = true;
	if (ima.count({x+1, y+1}) && !stabilan(x+1, y+1))
		ok = false;
	if (ok && ima.count({x, y+1}) && !stabilan(x, y+1))
		ok = false;
	if (ok && ima.count({x-1, y+1}) && !stabilan(x-1, y+1))
		ok = false;
	ima.insert({x, y});
	return ok;
}

void preispitaj(int x, int y) {
	auto it = ptoid.find({x, y});
	if (it == ptoid.end())
		return;
	int pid = it->second;
	if (!ima.count({x, y}))
		return;
	bool staro = bris.count(pid);
	bool novo = obrisiv(x, y);
	if (staro && !novo)
		bris.erase(pid);
	else if (!staro && novo)
		bris.insert(pid);
}

int sol[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
		ima.insert({x[i], y[i]});
		ptoid[{x[i], y[i]}] = i;
	}

	for (int i=0; i<n; i++) {
		if (obrisiv(x[i], y[i])) {
			bris.insert(i);
		}
	}

	for (int korak=0; korak<n; korak++) {
		int j;
		// cerr << "brisivi:";
		// for (int x : bris)
		// 	cerr << ' ' << x;
		// cerr << '\n';
		if (korak % 2)
			j = *bris.begin();
		else
			j = *bris.rbegin();
		int p = x[j];
		int q = y[j];
		ima.erase({p, q});
		bris.erase(j);
		sol[korak] = j;
		preispitaj(p+1, q-1);
		preispitaj(p-1, q-1);
		preispitaj(p, q-1);
		preispitaj(p+1, q+1);
		preispitaj(p-1, q+1);
		preispitaj(p, q+1);
		preispitaj(p-1, q);
		preispitaj(p-2, q);
		preispitaj(p+1, q);
		preispitaj(p+2, q);
	}

	int z = 0;
	for (int i=0; i<n; i++) {
		// cerr << sol[i] << ' ';
		z = (z*1ll*n + sol[i]) % 1000000009;
	}
	cout << z << '\n';
}