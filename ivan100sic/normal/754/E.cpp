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

bool prost(int x) {
	auto v = factor(x);
	return v.size() == 1 && v[0].second == 1;
}

int find_fft_mod(int order) {
	int x = (1ll << 30) - 2;
	x = x / order * order + 1;
	while (!prost(x))
		x -= order;
	return x;
}

int pw(int x, int y, int p) {
	if (y == 0)
		return 1;
	int z = pw(x, y >> 1, p);
	z = z * 1ll * z % p;
	if (y & 1)
		z = z * 1ll * x % p;
	return z;
}

int inv(int x, int p) {
	return pw(x, p-2, p);
}

int find_primitive_root(int p) {
	auto v = factor(p-1);
	for (int i=2; i; i++) {
		bool ok = true;
		for (auto e : v) {
			if (pw(i, (p-1) / e.first, p) == 1) {
				ok = false;
				break;
			}
		}
		if (ok)
			return i;
	}
	return -1;
}

int fft_p, fft_pr;

void dft(vector<int>& a, bool invert = false) {
	int n = a.size();
	vector<int> b(n, 0);
	int r = pw(fft_pr, (fft_p - 1) / n, fft_p);
	if (invert)
		r = inv(r, fft_p);
	for (int i=0; i<n; i++) {
		int mul = pw(r, i, fft_p);
		int w = 1;
		int bi = 0;
		for (int j=0; j<n; j++) {
			bi += a[j] * 1ll * w % fft_p;
			if (bi >= fft_p) bi -= fft_p;
			w = w * 1ll * mul % fft_p;
		}
		b[i] = bi;
	}
	swap(a, b);
}

int myhash(int x) {
	x = (unsigned)x * 841847431u;
	return (x ^ (x >> 3) ^ (x >> 15)) & 0xfffffff;
}

int U, V, N, M;
string sa[405];
int n, m;
int a[405][405], b[405][405];

template<class T>
void dbg(T a) {
	/*
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			cerr << a[i][j] << ' ';
		cerr << '\n';
	}
	cerr << '\n';
	*/
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> N >> M;
	for (int i=0; i<N; i++)
		cin >> sa[i];
	cin >> U >> V;

	n = max(N, U);
	m = max(M, V);

	fft_p = find_fft_mod(n*m);
	fft_pr = find_primitive_root(fft_p);

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			a[i][j] = myhash(sa[i % N][j % M]) % fft_p;
	}

	int ocekivano = 0;

	for (int i=0; i<U; i++) {
		string s;
		cin >> s;
		for (int j=0; j<V; j++) {
			b[U-1-i][V-1-j] = s[j] == '?' ? 0 : myhash(s[j]) % fft_p;

			ocekivano += b[U-1-i][V-1-j] * 1ll * b[U-1-i][V-1-j] % fft_p;
			if (ocekivano >= fft_p)
				ocekivano -= fft_p;		
		}
	}

	ocekivano = ocekivano * 1ll * n * m % fft_p;

	// dft po prvoj dimenziji
	for (int i=0; i<n; i++) {
		{
			vector<int> v(a[i], a[i] + m);
			dft(v);
			copy(v.begin(), v.end(), a[i]);	
		}

		{
			vector<int> v(b[i], b[i] + m);
			dft(v);
			copy(v.begin(), v.end(), b[i]);
		}
	}

	// dft po drugoj dimenziji
	for (int j=0; j<m; j++) {
		{
			vector<int> v(n);
			for (int i=0; i<n; i++)
				v[i] = a[i][j];
			dft(v);
			for (int i=0; i<n; i++)
				a[i][j] = v[i];
		}

		{
			vector<int> v(n);
			for (int i=0; i<n; i++)
				v[i] = b[i][j];
			dft(v);
			for (int i=0; i<n; i++)
				b[i][j] = v[i];
		}
	}

	dbg(a);
	dbg(b);

	// pomnozi
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			a[i][j] = a[i][j] * 1ll * b[i][j] % fft_p;

	dbg(a);

	// inverzni po prvoj dimenziji
	for (int i=0; i<n; i++) {
		vector<int> v(a[i], a[i] + m);
		dft(v, true);
		copy(v.begin(), v.end(), a[i]);	
	}

	// inverzni po drugoj dimenziji
	for (int j=0; j<m; j++) {
		vector<int> v(n);
		for (int i=0; i<n; i++)
			v[i] = a[i][j];
		dft(v, true);
		for (int i=0; i<n; i++)
			a[i][j] = v[i];
	}

	dbg(a);

	// proveri resenje
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cout << (a[(i + U - 1) % n][(j + V - 1) % m] == ocekivano);
		}
		cout << '\n';
	}

}