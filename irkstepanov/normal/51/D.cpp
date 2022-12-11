#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

struct datum {
	int zz;
	int zn;
	int nz;
	map<pii, int> nn;
	datum() : zz(0), zn(0), nz(0) {}

	void add(int a, int b) {
		if (a == 0 && b == 0) {
			++zz;
		} else if (a == 0) {
			++zn;
		} else if (b == 0) {
			++nz;
		} else {
			if (a < 0) {
				a = -a, b = -b;
			}
			int g = __gcd(abs(a), abs(b));
			a /= g, b /= g;
			++nn[{b, a}];
		}
	}

	void del(int a, int b) {
		if (a == 0 && b == 0) {
			--zz;
		} else if (a == 0) {
			--zn;
		} else if (b == 0) {
			--nz;
		} else {
			if (a < 0) {
				a = -a, b = -b;
			}
			int g = __gcd(abs(a), abs(b));
			a /= g, b /= g;
			--nn[{b, a}];
			if (nn[{b, a}] == 0) {
				nn.erase({b, a});
			}
		}
	}

	bool valid() const {
		if (zn) {
			return false;
		}
		if (nz) {
			return nn.empty();
		}
		if (sz(nn) > 1) {
			return false;
		}
		if (nn.empty()) {
			return true;
		}
		if (!zz) {
			return true;
		}
		return false;
	}
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    datum d;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
    	d.add(a[i - 1], a[i]);
    }

    if (d.valid()) {
    	cout << "0\n";
    	return 0;
    }

    for (int i = 0; i < n; ++i) {
    	if (i + 1 < n) {
    		d.del(a[i], a[i + 1]);
    	}
    	if (i - 1 >= 0) {
    		d.del(a[i - 1], a[i]);
    	}
    	if (i + 1 < n && i - 1 >= 0) {
    		d.add(a[i - 1], a[i + 1]);
    	}
    	if (d.valid()) {
    		cout << "1\n";
    		return 0;
    	}

    	if (i + 1 < n) {
    		d.add(a[i], a[i + 1]);
    	}
    	if (i - 1 >= 0) {
    		d.add(a[i - 1], a[i]);
    	}
    	if (i + 1 < n && i - 1 >= 0) {
    		d.del(a[i - 1], a[i + 1]);
    	}
    }

    cout << "2\n";

}