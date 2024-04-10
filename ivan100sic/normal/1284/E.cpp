#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	pt operator- (pt b) const {
		return {x-b.x, y-b.y};
	}
	bool operator< (pt b) const {
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

int n;
pt a[2505];

struct ang {
	bool operator() (const pt& a, const pt& b) const {
		bool u = a < pt{0, 0};
		bool v = b < pt{0, 0};
		if (u != v)
			return u;
		return det(a, b, {0, 0}) > 0;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].x >> a[i].y;

	ll alfa = 0;
	for (int i=0; i<n; i++) {
		vector<pt> b;
		for (int j=0; j<n; j++) {
			if (j != i)
				b.push_back(a[i] - a[j]);
		}
		int m = n-1;
		sort(b.begin(), b.end(), ang());
		int q = 0, g = 0;
		for (int p=0; p<m; p++) {
			while (g < m && det({0, 0}, b[p], b[q]) >= 0)
				q = (q+1) % m, g++;
			alfa += (g-1)*(g-2)/2;
			if (g == 0)
				q = (q+1) % m;
			else
				g--;
		}
	}

	ll bn = n*(n-1ll)*(n-2)*(n-3)/24;
	ll rez = 4*bn-alfa;
	cout << rez * (n-4) / 2 << '\n';	
}