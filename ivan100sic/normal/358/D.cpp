#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[3005], b[3005], c[3005];
int d[3005][6];

int rd(int* a, int i) {
	return i >= 0 ? a[i] : 0;
}

/*
012 0
021 1
102 2
120 3
201 4
210 5
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];
	for (int i=0; i<n; i++)
		cin >> c[i];
	
	if (n == 1) {
		cout << a[0] << '\n';
		return 0;
	}
	
	if (n == 2) {
		cout << max(a[0] + b[1], a[1] + b[0]) << '\n';
		return 0;
	}
	
	d[3][0] = a[0] + b[1] + b[2];
	d[3][1] = a[0] + a[2] + c[1];
	d[3][2] = a[1] + b[0] + b[2];
	d[3][3] = a[2] + a[0] + c[1];
	d[3][4] = a[1] + b[2] + b[0];
	d[3][5] = a[2] + b[1] + b[0];
	
	for (int i=4; i<=n; i++) {
		auto d = ::d[i-1];
		auto p = ::d[i];
		int rise = max({d[0], d[2], d[4]});
		int fall = max({d[1], d[3], d[5]});
		int a  = rd(::a, i-1), b  = rd(::b, i-1), c  = rd(::c, i-1);
		int aa = rd(::a, i-2), bb = rd(::b, i-2), cc = rd(::c, i-2);
		
		p[0] = rise + b;
		p[1] = rise + a - bb + cc;
		p[2] = fall + b;
		p[3] = rise + a - bb + cc;
		p[4] = fall + b;
		p[5] = fall + a - aa + bb;
	}
	
	cout << *max_element(d[n], d[n]+6) << '\n';
}