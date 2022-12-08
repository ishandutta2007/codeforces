/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<double> cd;
typedef vector<complex<double>> vcd;

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1009;
//const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int base = 1e5;
const int digits = 5;

struct big
{
	vector <int> num;
	int sign;
};

bool operator < (const big& a, const big& b)
{
	if (a.num.size() != b.num.size())
	{
		return a.num.size() < b.num.size();
	}
	else
	{
		return a.num < b.num;
	}
}

bool operator > (const big& a, const big& b)
{
	if (a.num.size() != b.num.size())
	{
		return a.num.size() > b.num.size();
	}
	else
	{
		return a.num > b.num;
	}
}

struct my_complex
{
	long double real, imag;
	my_complex(long double a, long double b) : real(a), imag(b)
	{
	}
	my_complex()
	{
	}
};

my_complex operator * (const my_complex& a, const my_complex& b)
{
	return { a.real * b.real - a.imag * b.imag, a.imag * b.real + a.real * b.imag };
}

my_complex operator - (const my_complex& a, const my_complex& b)
{
	return { a.real - b.real, a.imag - b.imag };
}

my_complex operator + (const my_complex& a, const my_complex& b)
{
	return { a.real + b.real, a.imag + b.imag };
}

typedef my_complex bse;

bse w[(int)5e6];

void fft(vector<bse>& a, bool invert) {
	int n = (int)a.size();

	for (int i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if (i < j)
			swap(a[i], a[j]);
	}

	int it = 0;
	for (int len = 2; len <= n; len <<= 1) {
		for (int i = 0; i < n; i += len) {
			int jt = it;
			for (int j = 0; j < len / 2; ++j) {
				bse u = a[i + j], v = a[i + j + len / 2] * w[jt];
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				jt++;
			}
		}
		it += len / 2;
	}
	if (invert)
	{
		reverse(a.begin() + 1, a.begin() + n);
		for (int i = 0; i < n; i++)
		{
			a[i].imag /= n;
		}
	}
}

vector <bse> fa, fb;

bool newton = false;

vector <int> multiply(const vector<int>& a, const vector<int>& b)
{
	size_t n = 1;
	while (n < a.size() + b.size())  n <<= 1;
	fa.resize(n);
	for (int i = 0; i < n; i++)
	{
		if (i < (int)a.size() && i < (int)b.size())
		{
			fa[i] = bse(a[i], b[i]);
		}
		else if (i < (int)a.size())
		{
			fa[i] = bse(a[i], 0);
		}
		else if (i < (int)b.size())
		{
			fa[i] = bse(0, b[i]);
		}
		else
		{
			fa[i] = bse(0, 0);
		}
	}
	fft(fa, false);
	for (size_t i = 0; i < n; ++i)
		fa[i] = fa[i] * fa[i];
	fft(fa, true);
	vector <int> res(n);
	for (size_t i = 0; i < (int)res.size(); ++i)
	{
		res[i] = (ll(fa[i].imag / 2 + 0.5)) % 1009;
	}
	while (!res.empty() && res.back() == 0)
	{
		res.pop_back();
	}
	return res;
}

vector<int> c;

vector<int> foo(int l, int r) {
	if (r - l == 1) {
		vector<int> a(c[l] + 1, 1);
		return a;
	}
	return multiply(foo(l, l + r >> 1), foo(l + r >> 1, r));
}

void solve(){
	int it = 0;
	for (int len = 2; ; len *= 2)
	{
		long double ang = 2 * PI / len;
		bse wlen = bse(cos(ang), sin(ang));
		bse u(1, 0);
		for (int i = 0; i < len / 2; i++)
		{
			w[it++] = u;
			u = u * wlen;
			if (it >= 5e6)
			{
				break;
			}
		}
		if (it >= 5e6)
		{
			break;
		}
	}
	int n, m, k; cin >> n >> m >> k;
	c.resize(m);
	for (int i = 0; i < n; i++) {
		int x; cin >> x; x--;
		c[x]++;
	}
	vector<int> kek = foo(0, m);
	cout << kek[k] << endl;
	return;
}