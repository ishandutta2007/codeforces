#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// vi mene zajebavate

static string s;
static int n, k;
static bool p[2][52][201][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> k;
	n = s.size();
	p[0][0][100][0] = 1;
	for (int i=0; i<n; i++) {
		auto q = p[i%2];
		auto r = p[1-i%2];
		memset(r, 0, sizeof(p[0]));
		for (int j=0; j<=k; j++) {
			for (int x=100-i; x<=100+i; x++) {
				for (int d=0; d<2; d++) {
					if (!q[j][x][d])
						continue;
					// ostaje isto
					if (s[i] == 'T')
						r[j][x][d^1] |= 1;
					else
						r[j][x+2*d-1][d] |= 1;

					// menja se
					if (s[i] == 'T')
						r[j+1][x+2*d-1][d] |= 1;
					else
						r[j+1][x][d^1] |= 1;
				}
			}
		}
	}
	const auto q = p[n%2];
	int sol = 0;
	for (int j=k; j>=0; j-=2)
		for (int x=0; x<=200; x++)
			for (int d=0; d<2; d++)
				if (q[j][x][d])
					sol = max(sol, abs(x-100));
	cout << sol << '\n';
}