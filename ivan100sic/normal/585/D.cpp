#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct mapped {
	ll tip;
	int prvi;

	mapped(ll tip=0, int prvi=-1e9) : tip(tip), prvi(prvi) {}

	bool operator< (const mapped& b) const {
		return prvi < b.prvi;
	}
};

int n;
int a[25][3];
map<pair<int, int>, mapped> mp;

void rek1(int i, int rem, int x=0, int y=0, int z=0, ll t=0) {
	if (i == rem) {
		auto& v = mp[{y-x, z-x}];
		v = max(v, mapped{t, x});
		return;
	}

	rek1(i+1, rem, x+a[i][0], y+a[i][1], z, t+(0b011ll << 3*i));
	rek1(i+1, rem, x+a[i][0], y, z+a[i][2], t+(0b101ll << 3*i));
	rek1(i+1, rem, x, y+a[i][1], z+a[i][2], t+(0b110ll << 3*i));
}

ll best_prvi = -1e18, best_tip1, best_tip2;

void rek2(int i, int j, int rem, int x=0, int y=0, int z=0, ll t=0) {
	if (i == rem) {
		auto it = mp.find({x-y, x-z});
		if (it != mp.end()) {
			if (x + it->second.prvi > best_prvi) {
				best_prvi = x + it->second.prvi;
				best_tip1 = it->second.tip;
				best_tip2 = t;
			}
		}
		return;
	}

	rek2(i+1, j+1, rem, x+a[i][0], y+a[i][1], z, t+(0b011ll << 3*j));
	rek2(i+1, j+1, rem, x+a[i][0], y, z+a[i][2], t+(0b101ll << 3*j));
	rek2(i+1, j+1, rem, x, y+a[i][1], z+a[i][2], t+(0b110ll << 3*j));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<3; j++) {
			cin >> a[i][j];
		}
	}

	rek1(0, n/2);
	rek2(n/2, 0, n);

	if (best_prvi == -1e18) {
		cout << "Impossible\n";
		return 0;
	}
	string s, u = "LMW";
	for (int i=0; i<n/2*3; i++)
		if (best_tip1 & (1ll << i))
			s += u[i%3];
	for (int i=0; i<(n-n/2)*3; i++)
		if (best_tip2 & (1ll << i))
			s += u[i%3];

	for (int i=0; i<2*n; i++) {
		cout << s[i];
		if (i % 2)
			cout << '\n';
	}
}