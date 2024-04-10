// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int HI = 1005;
const int OD = 100;
int mex[6][6][6][HI][3];
int perioda[6][6][6];

struct mexer {
	vector<int> a;

	void add(int x) {
		a.push_back(x);
	}

	int get() const {
		string b(a.size() + 1, 0);
		for (int x : a)
			if (x < (int)b.size())
				b[x] = 1;
		for (int i=0; i<(int)b.size(); i++)
			if (!b[i])
				return i;
		return -1;
	}
};

void calc() {
	for (int x=1; x<=5; x++) {
		for (int y=1; y<=5; y++) {
			for (int z=1; z<=y; z++) {

				auto a = mex[x][y][z];

				for (int k=1; k<HI; k++) {
					for (int i=0; i<3; i++) {
						mexer m;
						m.add(a[max(0, k-x)][0]);
						if (i != 1)
							m.add(a[max(0, k-y)][1]);
						if (i != 2)
							m.add(a[max(0, k-z)][2]);
						a[k][i] = m.get();
					}
				}

				auto napravi = [&](int b) {
					array<int, 18> c;
					for (int i=0; i<6; i++)
						for (int j=0; j<3; j++)
							c[3*i+j] = a[b+i][j];
					return c;
				};

				auto baza = napravi(OD);
				for (int i=OD+1; i<HI-10; i++) {
					if (napravi(i) == baza) {
						perioda[x][y][z] = i - OD;
						break;
					}
				}
			}
		}
	}
}

int mget(ll x, int y, int* xx) {
	x = max(x, 0ll);
	if (x >= OD)
		x = (x - OD) % perioda[xx[0]][xx[1]][xx[2]] + OD;
	return mex[xx[0]][xx[1]][xx[2]][x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	calc();

	int t;
	cin >> t;
	while (t--) {
		int n, x[3];
		cin >> n >> x[0] >> x[1] >> x[2];
		if (x[2] > x[1])
			swap(x[2], x[1]);
		vector<ll> a(n);

		for (ll& x : a)
			cin >> x;

		int xr = 0;
		for (int i=0; i<n; i++)
			xr ^= mget(a[i], 0, x);

		int opts = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<3; j++) {
				int tmp = xr ^ mget(a[i], 0, x) ^ mget(a[i] - x[j], j, x);
				if (tmp == 0) {
					opts++;
				}
			}
		}

		cout << opts << '\n';
	}
}

// I will still practice daily...