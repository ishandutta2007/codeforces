// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(x) (cerr << "ln " << __LINE__ << ": " << #x << " = " << (x) << '\n')
#else
#define dbg(x) {}
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 2000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

vector<pair<int, int>> factor_small(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int p = f[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

vector<pair<int, int>> fs[2005];
vector<int> ugly;
unsigned z[420][420][420];

int freq[2005], prod = 1;
int ord[2005];

void dod(int x) {
	for (auto [p, e] : fs[x]) {
		prod /= freq[p] + 1;
		freq[p] += e;
		prod *= freq[p] + 1;
	}
}

void oduz(int x) {
	for (auto [p, e] : fs[x]) {
		prod /= freq[p] + 1;
		freq[p] -= e;
		prod *= freq[p] + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int x=1; x<=2000; x++)
		fs[x] = factor_small(x);

	for (int x=1; x<=2000; x++) {
		bool ok = 1;
		for (auto [p, e] : fs[x]) {
			if (p <= 11) {
				ok = 0;
			}
		}
		if (ok) {
			ugly.push_back(x);
		}
	}

	dbg(ugly.size());

	int g = ugly.size();
	for (int i=0; i<g; i++) {
		dod(ugly[i]);
		for (int j=i; j<g; j++) {
			dod(ugly[j]);
			for (int k=j; k<g; k++) {
				dod(ugly[k]);
				z[i][j][k] = prod;
				z[i][k][j] = prod;
				z[j][i][k] = prod;
				z[j][k][i] = prod;
				z[k][i][j] = prod;
				z[k][j][i] = prod;
				oduz(ugly[k]);
			}
			oduz(ugly[j]);
		}
		oduz(ugly[i]);
	}

	for (int i=1; i<=2000; i++) {
		ord[i] = ord[i-1];
		while (ord[i]+1 < g && ugly[ord[i]+1] <= i)
			ord[i]++;
	}

	for (int i=1; i<g; i++)
	for (int j=0; j<g; j++)
	for (int k=0; k<g; k++)
	{
		z[i][j][k] += z[i-1][j][k];
	}

	for (int i=0; i<g; i++)
	for (int j=1; j<g; j++)
	for (int k=0; k<g; k++)
	{
		z[i][j][k] += z[i][j-1][k];
	}

	for (int i=0; i<g; i++)
	for (int j=0; j<g; j++)
	for (int k=1; k<g; k++)
	{
		z[i][j][k] += z[i][j][k-1];
	}

	int a, b, c;
	cin >> a >> b >> c;

	unsigned sol = 0;

	for (int x2 =1, e2 =1; x2             <=a; x2 *= 2, e2 ++)
	for (int x3 =1, e3 =1; x2*x3          <=a; x3 *= 3, e3 ++)
	for (int x5 =1, e5 =1; x2*x3*x5       <=a; x5 *= 5, e5 ++)
	for (int x7 =1, e7 =1; x2*x3*x5*x7    <=a; x7 *= 7, e7 ++)
	for (int x11=1, e11=1; x2*x3*x5*x7*x11<=a; x11*=11, e11++)
	{
		int o1 = ord[a/(x2*x3*x5*x7*x11)];

		for (int y2 =1, f2 =0; y2             <=b; y2 *= 2, f2 ++)
		for (int y3 =1, f3 =0; y2*y3          <=b; y3 *= 3, f3 ++)
		for (int y5 =1, f5 =0; y2*y3*y5       <=b; y5 *= 5, f5 ++)
		for (int y7 =1, f7 =0; y2*y3*y5*y7    <=b; y7 *= 7, f7 ++)
		for (int y11=1, f11=0; y2*y3*y5*y7*y11<=b; y11*=11, f11++)
		{
			int o2 = ord[b/(y2*y3*y5*y7*y11)];

			for (int z2 =1, g2 =0; z2             <=c; z2 *= 2, g2 ++)
			for (int z3 =1, g3 =0; z2*z3          <=c; z3 *= 3, g3 ++)
			for (int z5 =1, g5 =0; z2*z3*z5       <=c; z5 *= 5, g5 ++)
			for (int z7 =1, g7 =0; z2*z3*z5*z7    <=c; z7 *= 7, g7 ++)
			for (int z11=1, g11=0; z2*z3*z5*z7*z11<=c; z11*=11, g11++)
			{
				int o3 = ord[c/(z2*z3*z5*z7*z11)];

				sol += z[o1][o2][o3] * (e2+f2+g2) * (e3+f3+g3) * (e5+f5+g5) * (e7+f7+g7) * (e11+f11+g11);
			}
		}
	}

	cout << (sol & 0x3fffffff) << '\n';
}

// I will still practice daily...