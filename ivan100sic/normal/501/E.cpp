#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], l = 1, r = 0;
bool is_bomb[100005];
int c_bomb, neg, odd;
int f[100005];

void addf(int x) {
	x = a[x];
	f[x]++;
	if (f[x] == 0)
		neg--;

	if (f[x] % 2 == 0)
		odd--;
	else
		odd++;
}

void remf(int x) {
	x = a[x];
	f[x]--;

	if (f[x] == -1)
		neg++;

	if (f[x] % 2 == 0)
		odd--;
	else
		odd++;
}

void addc(int x) {
	c_bomb += is_bomb[x];
}

void remc(int x) {
	c_bomb -= is_bomb[x];
}

int bl = 1, br = 0;

pair<int, int> zona_b(int l, int r) {
	if (r < n+1-r || l > n+1-l)
		return {n+1-r, n+1-l};
	if (l+r < n+1)
		return {r+1, n+1-l};
	return {n+1-r, l-1};
}

void go_zona_b(int tl, int tr) {
	while (br < tr) remf(++br), remc(br);
	while (bl > tl) remf(--bl), remc(bl);
	while (br > tr) addf(br), addc(br--);
	while (bl < tl) addf(bl), addc(bl++);
}

void extend_r() {
	remc(r+1);
	addf(r+1);
	auto [tl, tr] = zona_b(l, r+1);
	go_zona_b(tl, tr);
	r++;
}

void retract_l() {
	if (l == r)
		extend_r();
	addc(l);
	remf(l);
	auto [tl, tr] = zona_b(l+1, r);
	go_zona_b(tl, tr);
	l++;
}

/*
6
1 3 2 1 1 2
*/

bool ok() {
	// cerr << l << ' ' << r << ' ' << bl << ' ' << br << ' ' << c_bomb << ' ' << neg << ' ' << odd << '\n';
	// cerr << "f = " << f[1] << ' ' << f[2] << ' ' << f[3] << '\n';
	// cerr << '\n';
	return !c_bomb && !neg && odd <= 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=1; i<=n; i++) {
		is_bomb[i] = a[i] != a[n+1-i];
		c_bomb += is_bomb[i];
	}

	ll sol = 0;

	while (1) {
		while (r < l || (r < n && !ok()))
			extend_r();
		if (ok())
			sol += n-r+1;
		// cerr << l << ' ' << r << ' ' << ok() << '\n';
		if (l < n) {
			retract_l();
		} else {
			break;
		}
	}

	cout << sol << '\n';
}