#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int mod = 119 * (1 << 23) + 1;
const int kmax = 16;
int degs[1 << kmax];

void add(int& a, int b)
{
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void mul(int& a, int b)
{
	ll c = ll(a) * ll(b);
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

void sub(int& a, int b)
{
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

int binpow(int a, int n)
{
	int ans = 1;
	while (n) {
		if (n & 1) {
			mul(ans, a);
		}
		mul(a, a);
		n >>= 1;
	}
	return ans;
}

const int revk = binpow(1 << kmax, mod - 2);
const int root = binpow(31, 1 << (23 - kmax));

int rev[1 << kmax];

vector<int> fft(const vector<int>& a) // sz(a) == (1 << kmax) - 1
{
	vector<int> b(1 << kmax);
	for (int i = 0; i < (1 << kmax); ++i) {
		b[i] = a[rev[i]];
	}
	for (int h = 0; h < kmax; ++h) {
		vector<int> c(1 << kmax);
		int step = (1 << (kmax - h - 1));
		for (int i = 0; i < (1 << kmax); i += (1 << (h + 1))) {
			int ptr = 0;
			for (int p = 0; p < (1 << h); ++p, ptr += step) {
				int val = b[i + (1 << h) + p];
				mul(val, degs[ptr]);

				add(c[i + p], val);
				add(c[i + p], b[i + p]);

				sub(c[i + (1 << h) + p], val);
				add(c[i + (1 << h) + p], b[i + p]);
			}
		}
		b.swap(c);
	}
	return b;
}

vector<int> revfft(const vector<int>& a)
{
	vector<int> b = fft(a);
	reverse(b.begin() + 1, b.end());
	for (int i = 0; i < (1 << kmax); ++i) {
		mul(b[i], revk);
	}
	return b;
}

struct matrix
{
	vector<int> m[2][2];
	matrix(bool one = false)
	{
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				m[i][j] = vector<int>(1 << kmax);
				if (i == j && one) {
					m[i][j][0] = 1;
				}
			}
		}
	}
};

matrix operator*(matrix& a, matrix& b)
{
	matrix res;
	matrix c, d;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			c.m[i][j] = fft(a.m[i][j]);
			d.m[i][j] = fft(b.m[i][j]);
		}
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				for (int t = 0; t < (1 << kmax); ++t) {
					int val = c.m[i][k][t];
					mul(val, d.m[k][j][t]);
					add(res.m[i][j][t], val);
				}
			}
			res.m[i][j] = revfft(res.m[i][j]);
			for (int t = (1 << (kmax - 1)); t < (1 << kmax); ++t) {
				res.m[i][j][t] = 0;
			}
		}
	}
	return res;
}

matrix binpow(matrix a, int n)
{
	matrix ans(true);
	while (n) {
		if (n & 1) {
			ans = ans * a;
		}
		a = a * a;
		n >>= 1;
	}
	return ans;
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	degs[0] = 1;
	for (int i = 1; i < (1 << kmax); ++i) {
		degs[i] = degs[i - 1];
		mul(degs[i], root);
		assert(degs[i] != 1);
	}

	int oldest = -1;
	rev[0] = 0;
	for (int i = 1; i < (1 << kmax); ++i) {
		if (!(i & (i - 1))) {
			++oldest;
		}
		rev[i] = (rev[i ^ (1 << oldest)] | (1 << (kmax - oldest - 1)));
	}

	matrix m;
	m.m[0][0][0] = m.m[0][0][1] = 1;
	m.m[0][1][1] = 1;
	m.m[1][0][0] = 1;

	int n, k;
	cin >> n >> k;

	m = binpow(m, n - 1);
	matrix f;
	f.m[0][0][0] = f.m[0][0][1] = 1;
	f.m[1][0][0] = 1;

	matrix res = m * f;
	for (int i = 1; i <= k; ++i) {
		cout << res.m[0][0][i] << " ";
	}
	cout << "\n";

}