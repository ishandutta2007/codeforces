#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int x[10] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
int y[10] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};

bool ima(int a, int b) {
	for (int i=0; i<10; i++)
		if (x[i] == a && y[i] == b)
			return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;

	int c = 0;

	for (int dx=-4; dx<=4; dx++) {
		for (int dy=-4; dy<=4; dy++) {
			int ok = 1;
			for (char c : s) {
				int u = dx + x[c-'0'];
				int v = dy + y[c-'0'];
				if (!ima(u, v))
					ok = 0;
			}
			if (ok)
				c++;
		}
	}

	cout << (c == 1 ? "YES\n" : "NO\n");
}