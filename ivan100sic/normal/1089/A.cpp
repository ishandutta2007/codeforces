#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool ok(int x, int y, int h) {
	int a = max(x, y);
	int b = min(x, y);
	if (a < h)
		return false;
	if (a == h)
		return b <= h-2;
	return a-b == 2;
}

pair<int, int> pr[205][205][4][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(pr, 255, sizeof(pr));

	pr[0][0][0][0] = {0, 0};

	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			int h = 25;
			if (i + j == 4)
				h = 15;

			for (int a=0; a<=200; a++) {
				for (int b=0; b<=200; b++) {
					if (!ok(a, b, h))
						continue;

					int w1 = a > b;
					int w2 = b > a;

					for (int x=0; x<=200-a; x++) {
						for (int y=0; y<=200-b; y++) {
							if (pr[x][y][i][j].first == -1)
								continue;
							pr[x+a][y+b][i+w1][j+w2] = {a, b};
						}
					}
				}
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int x, y, ibest = -1, jbest = -1, skorbest = -10;
		cin >> x >> y;

		for (int i=0; i<=3; i++) {
			for (int j=0; j<=3; j++) {
				if ((i == 3) ^ (j == 3)) {
					if (pr[x][y][i][j].first != -1) {
						if (i - j > skorbest) {
							skorbest = i - j;
							ibest = i;
							jbest = j;
						}
					}
				}
			}
		}

		if (skorbest == -10) {
			cout << "Impossible\n";
			continue;
		}

		cout << ibest << ":" << jbest << '\n';

		vector<string> stvari;

		while (x + y) {
			auto p = pr[x][y][ibest][jbest];
			int a = p.first;
			int b = p.second;

			int w1 = a > b;
			int w2 = b > a;

			ibest -= w1;
			jbest -= w2;

			x -= a;
			y -= b;
			
			stvari.push_back(to_string(a) + ":" + to_string(b));
		}

		reverse(stvari.begin(), stvari.end());
		for (string s : stvari)
			cout << s << ' ';
		cout << '\n';
	}
}