#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	int x, y;
};

bool kv(int x, int y, int r, pt p) {
	p.x -= x;
	p.y -= y;
	if (p.x < 0 || p.x > r || p.y < 0 || p.y > r)
		return false;
	return min({p.x, r-p.x, p.y, r-p.y}) == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<pt> a(4*n+1);
	for (pt& p : a)
		cin >> p.x >> p.y;
	for (int x=0; x<=50; x++)
		for (int y=0; y<=50; y++)
			for (int r=1; r<=50; r++) {
				int z=0, u=0, v=0;
				for (pt p : a)
					if (!(kv(x, y, r, p)))
						z++, u=p.x, v=p.y;
				if (z == 1) {
					cout << u << ' ' << v << '\n';
					return 0;
				}
			}
}