#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
deque<char> a[305][305], b[305][305];
int r[305], c[305], r2[305], c2[305];

struct potez {
	int x1, y1, x2, y2;
};

basic_string<potez> sol;

void mv(int x1, int y1, int x2, int y2) {
	sol += {x1, y1, x2, y2};
	char c = a[x1][y1].back();
	a[x1][y1].pop_back();
	a[x2][y2].push_front(c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			string s;
			cin >> s;
			a[i][j] = deque<char>(s.begin(), s.end());
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			string s;
			cin >> s;
			b[i][j] = deque<char>(s.begin(), s.end());
		}
	}

	// nadji anchor
	int x = -1, y = -1, tot = 0;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			tot += a[i][j].size();
			r[i] += a[i][j].size();
			c[j] += a[i][j].size();
			r2[i] += b[i][j].size();
			c2[j] += b[i][j].size();
		}
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (r[i] + c[j] - r2[i] - c2[j] <= 0) {
				x = i;
				y = j;
			}
		}
	}

	// gurni xy negde drugde
	int xt = (x == n ? 1 : x+1);
	int yt = (y == m ? 1 : y+1);
	while (a[x][y].size())
		mv(x, y, xt, y);
	// gurni redove i kolone negde
	for (int i=1; i<=n; i++)
		while (a[i][y].size())
			mv(i, y, i, yt);
	for (int j=1; j<=m; j++)
		while (a[x][j].size())
			mv(x, j, xt, j);

	/*
	cerr << "prvo guranje\n";

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cerr << '.';
			for (char c : a[i][j])
				cerr << c;
			cerr << ' ';
		}
		cerr << '\n';
	}
	*/

	// sastavi nule i keceve
	for (int i=1; i<=n; i++) {
		if (i == x)
			continue;
		for (int j=1; j<=m; j++) {
			if (j == y)
				continue;
			while (a[i][j].size()) {
				if (a[i][j].back() == '0') {
					mv(i, j, x, j);
				} else {
					mv(i, j, i, y);
				}
			}
		}
	}

	// sastavi master string
	deque<char> master = b[x][y];
	for (int i=1; i<=n; i++) {
		if (i == x)
			continue;
		for (char c : b[i][y])
			master.push_back(c);
	}
	for (int j=1; j<=m; j++) {
		if (j == y)
			continue;
		for (char c : b[x][j])
			master.push_back(c);
	}
	for (int i=1; i<=n; i++) {
		if (i == x)
			continue;
		for (int j=1; j<=m; j++) {
			if (j == y)
				continue;
			for (char c : b[i][j])
				master.push_back(c);
		}
	}

	{
		int xf = -1, yf = -1;
		for (int k=(int)master.size()-1; k>=0; k--) {
			if (xf == -1) {
				for (int i=1; i<=n; i++) {
					if (i == x)
						continue;
					if (a[i][y].size())
						xf = i;
				}
			}

			if (yf == -1) {
				for (int j=1; j<=m; j++) {
					if (j == y)
						continue;
					if (a[x][j].size())
						yf = j;
				}
			}

			if (master[k] == '0')
				mv(x, yf, x, y);
			else
				mv(xf, y, x, y);

			if (xf > 0 && a[xf][y].empty())
				xf = -1;
			if (yf > 0 && a[x][yf].empty())
				yf = -1;
		}
	}

	// sad sastavi ostale, istim redom
	for (int i=n; i>=1; i--) {
		if (i == x)
			continue;
		for (int j=m; j>=1; j--) {
			if (j == y)
				continue;

			for (int k=0; k<(int)b[i][j].size(); k++) {
				mv(x, y, i, y);
				mv(i, y, i, j);
			}
		}
	}

	for (int j=m; j>=1; j--) {
		if (j == y)
			continue;
		for (int k=0; k<(int)b[x][j].size(); k++)
			mv(x, y, x, j);
	}

	for (int i=n; i>=1; i--) {
		if (i == x)
			continue;
		for (int k=0; k<(int)b[i][y].size(); k++)
			mv(x, y, i, y);
	}

	cout << sol.size() << '\n';
	for (auto e : sol) {
		cout << e.x1 << ' ' << e.y1 << ' ' << e.x2 << ' ' << e.y2 << "\n";
	}
}