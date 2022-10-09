#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 100000;

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

vector<pair<int, int>> factor(int x) {
	vector<pair<int, int>> v;
	for (int p : prosti) {
		if (x % p == 0) {
			int c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.push_back({p, c});
		}			
	}

	if (x > 1) {
		v.push_back({x, 1});
	}
	return v;
}

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int divisors(vector<pair<int, int>>& v) {
	int pr = 1;
	for (auto p : v) {
		pr *= p.second + 1;
	}
	return pr;
}



int brut(int a, int b, int c) {
	set<vector<int>> s;
	for (int i=1; i<=a; i++)
		for (int j=1; j<=b; j++)
			for (int k=1; k<=c; k++) {
				if (a%i == 0 && b%j == 0 && c%k == 0) {
					vector<int> v = {i, j, k};
					sort(v.begin(), v.end());
					s.insert(v);
				}
			}
	return s.size();
}

int uslov[8][8][8];

int divc[100005];

int divisors(int x) {
	return divc[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;

	for (int i=1; i<8; i++)
		for (int j=i; j<8; j++)
			for (int k=j; k<8; k++) {

				// ako postoji permutacija tako da je ok
				int v[3] = {i, j, k};
				sort(v, v+3);
				int c = 0;
				for (int rep=0; rep<6; rep++) {
					if ((v[0] & 1) && (v[1] & 2) && (v[2] & 4))
						c = 1;
					next_permutation(v, v+3);
				}

				uslov[i][j][k] = c;
			}

	for (int i=1; i<=100000; i++)
		for (int j=i; j<=100000; j+=i)
			divc[j]++;

	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		int xa = divisors(a);
		int xb = divisors(b);
		int xc = divisors(c);

		int xab = divisors(gcd(a, b));
		int xbc = divisors(gcd(b, c));
		int xca = divisors(gcd(c, a));

		int xabc = divisors(gcd(gcd(a, b), c));

		int xax = xa-xab-xca+xabc;
		int xbx = xb-xbc-xab+xabc;
		int xcx = xc-xca-xbc+xabc;
		int xabx = xab-xabc;
		int xbcx = xbc-xabc;
		int xcax = xca-xabc;

		int g[8] = {0, xax, xbx, xabx, xcx, xcax, xbcx, xabc};
		int sol = 0;

		/*
		for (int i=1; i<8; i++)
			cerr << g[i] << ' ';
		cerr << '\n';
		*/

		for (int i=1; i<8; i++)
			for (int j=i; j<8; j++)
				for (int k=j; k<8; k++) {
					int u = 0;

					// preskacemo ako ne ispunjavaju uslov mecinga
					if (!uslov[i][j][k])
						continue;

					if (i == j && j == k)
						u = g[i] * (g[i]+1) * (g[i]+2) / 6;
					else if (i == j)
						u = g[i] * (g[i]+1) / 2 * g[k];
					else if (i == k)
						u = g[i] * (g[i]+1) / 2 * g[j];
					else if (j == k)
						u = g[i] * g[j] * (g[j]+1) / 2;
					else
						u = g[i] * g[j] * g[k];
					sol += u;
				}
		cout << sol << '\n';

		// cerr << "brut: " << brut(a, b, c) << '\n';

	}

}