#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	int id;
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

int n;
string s;
pt a[2005];

bool cmp_lex(pt a, pt b) {
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

struct cmp_det {
	pt p;
	cmp_det(pt p) : p(p) {}
	bool operator() (pt a, pt b) const {
		return det(p, a, b) < 0;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].id = i+1;
	}
	cin >> s;

	sort(a, a+n, cmp_lex);
	for (int i=1; i<n-1; i++) {
		sort(a+i, a+n, cmp_det(a[i-1]));
		if (s[i-1] == 'L')
			reverse(a+i, a+n);
	}
	for (int i=0; i<n; i++)
		cout << a[i].id << " \n"[i == n-1];


}