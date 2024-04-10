#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct envelope {
	int x, y, d, p, id;
	bool operator< (const envelope& o) const {
		return x > o.x;
	}
} a[5005];
int n, w, h;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> w >> h;
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].p = -1;
		a[i].id = i+1;
	}
	sort(a, a+n);
	int sol = 0, k = -1;
	for (int i=0; i<n; i++) {
		a[i].d = 1;
		a[i].p = -1;
		for (int j=0; j<i; j++) {
			if (a[j].x > a[i].x && a[j].y > a[i].y) {
				if (a[j].d + 1 > a[i].d) {
					a[i].d = a[j].d + 1;
					a[i].p = j;
				}
			}
		}
		if (w < a[i].x && h < a[i].y) {
			if (a[i].d > sol) {
				sol = a[i].d;
				k = i;
			}
		}
	}
	cout << sol << '\n';
	for (int i=k; i!=-1; i=a[i].p) {
		cout << a[i].id << ' ';
	}
	cout << '\n';
}