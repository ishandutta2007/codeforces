#include <bits/stdc++.h>
using namespace std;

unsigned int tree[2505][2505];

int n, m, q;

void paint1(int x, int y, unsigned int c) {
	for (int u=x; u<=2504; u += u & -u) {
		for (int v=y; v<=2504; v += v & -v) {
			tree[u][v] ^= c;
		}
	}
}

void paint(int a, int b, int x, int y, unsigned int c) {
	b++;
	y++;
	paint1(a, x, c);
	paint1(a, y, c);
	paint1(b, x, c);
	paint1(b, y, c);
}

unsigned int get(int x, int y) {
	int c = 0;

	for (int u=x; u; u -= u & -u) {
		for (int v=y; v; v -= v & -v) {
			c ^= tree[u][v];
		}
	}

	// cerr << "result " << c << '\n';
	return c;
}

map<tuple<int, int, int, int>, int> box;

int p[100005];
unsigned int hashe[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;

	srand(time(nullptr) + n + m * 1337 + rand());

	for (int qq=1; qq<=q; qq++) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, x, b, y;
			cin >> a >> x >> b >> y;
			box[{a, x, b, y}] = qq;
			hashe[qq] = (rand() << 16) ^ rand();
			paint(a, b, x, y, hashe[qq]);

			// cerr << "hash: " << qq << ' ' << hashe[qq] << '\n';

		} else if (t == 2) {
			int a, x, b, y;
			cin >> a >> x >> b >> y;
			int qpre = box[{a, x, b, y}];
			paint(a, b, x, y, hashe[qpre]);
		} else {
			int a, x, b, y;
			cin >> a >> x >> b >> y;
			int c1 = get(a, x);
			int c2 = get(b, y);

			// cerr << c1 << ' ' << c2 << '\n';

			cout << (c1 == c2 ? "Yes\n" : "No\n");
		}
	}	
}