// Hydro submission #6319296fa6141d4b72cf4b22@1662593391692
/*******************************
| Author:  ybw051114
| Problem: C. Future Failure
| Contest: Codeforces - IndiaHacks 2nd Elimination 2017 (unofficial, unrated mirror, ICPC rules)
| URL:     https://codeforces.com/contest/838/problem/C
| When:    2022-09-08 07:06:04
|
| Memory:  256 MB
| Time:    3000 ms
*******************************/
#include <bits/stdc++.h>
#ifndef use_ios11
#define use_ios11
using namespace std;
#define log(a) cerr << "\033[32m[DEBUG] " << #a << '=' << (a) << " @ line " << __LINE__ << "\033[0m" << endl
typedef long long ll;
#define pb push_back
typedef pair<int, int> pii;

#define mem(p) memset(&p, 0, sizeof(p))
typedef pair<long long, long long> pll;
#define ir(x) \
	int x;    \
	yin >> x
#define foor(action, actionx2, actionx4, width)         \
	do                                                  \
	{                                                   \
		unsigned long __width = (unsigned long)(width); \
		unsigned long __increment = __width >> 2;       \
		for (; __increment > 0; __increment--)          \
		{                                               \
			actionx4;                                   \
		}                                               \
		switch (__width & 3)                            \
		{                                               \
		case 2:                                         \
			actionx2;                                   \
			break;                                      \
		case 3:                                         \
			actionx2;                                   \
		case 1:                                         \
			action;                                     \
			break;                                      \
		}                                               \
	} while (0)
struct ins
{
	int ans;
	ins()
	{
		ans = 1;
	}
#define endl '\n'
	void read()
	{
	}
	void read1(char &s)
	{
		char c = getchar();
		for (; !isprint(c) || c == ' ' || c == '\n' || c == '\t'; c = getchar())
			;
		s = c;
		if (c == EOF)
			ans = 0;
	}
	void read1(string &s)
	{
		s = "";
		char c = getchar();
		for (; !isprint(c) || c == ' ' || c == '\n' || c == '\t'; c = getchar())
			;
		for (; isprint(c) && c != ' ' && c != '\n' && c != '\t'; c = getchar())
			s += c;
		if (c == EOF)
			ans = 0;
	}
	void read1(char *s)
	{
		char c = getchar();
		int tt = 0;
		for (; !isprint(c) || c == ' ' || c == '\n' || c == '\t'; c = getchar())
			;
		for (; isprint(c) && c != ' ' && c != '\n' && c != '\t'; c = getchar())
			s[tt++] = c;
		s[tt] = '\0';
		if (c == EOF)
			ans = 0;
	}

	template <typename T>
	void read1(T &n)
	{
		T x = 0;
		int f = 1;
		char c = getchar();
		for (; !isdigit(c); c = getchar())
		{
			if (c == '-')
				f = -1;
			if (c == EOF)
			{
				ans = 0;
				return;
			}
		}
		for (; isdigit(c); c = getchar())
			x = x * 10 + c - 48;
		n = x * f;
		if (c == EOF)
			ans = 0;
		if (c != '.')
			return;
		T l = 0.1;
		while ((c = getchar()) <= '9' && c >= '0')
			x = x + (c & 15) * l, l *= 0.1;
		n = x * f;
		if (c == EOF)
			ans = 0;
	}
	void write() {}
	void write1(string s)
	{
		int n = s.size();
		for (int i = 0; i < n; i++)
			putchar(s[i]);
	}
	void write1(const char *s)
	{
		int n = strlen(s);
		for (int i = 0; i < n; i++)
			putchar(s[i]);
	}
	void write1(char *s)
	{
		int n = strlen(s);
		for (int i = 0; i < n; i++)
			putchar(s[i]);
	}

	void write1(char s)
	{
		putchar(s);
	}
	void write1(float s, int x = 6)
	{
		char y[10001];
		sprintf(y, "%%.%df", x);
		printf(y, s);
	}
	void write1(double s, int x = 6)
	{
		char y[10001];
		sprintf(y, "%%.%dlf", x);
		printf(y, s);
	}
	void write1(long double s, int x = 6)
	{
		char y[10001];
		sprintf(y, "%%.%dLf", x);
		printf(y, s);
	}
	template <typename T>
	void write1(T n)
	{
		if (n < 0)
			n = -n, putchar('-');
		if (n > 9)
			write1(n / 10);
		putchar('0' + n % 10);
	}
	friend ins operator>>(ins x, char *n);
	template <typename T>
	friend ins operator>>(ins x, T &n);
	template <typename T>
	friend ins operator<<(ins x, T n);
	operator bool()
	{
		return ans;
	}
};

ins operator>>(ins x, char *n)
{
	if (!x.ans)
		return x;
	x.read1(n);
	return x;
}

template <typename T>
ins operator>>(ins x, T &n)
{
	if (!x.ans)
		return x;
	x.read1(n);
	return x;
}
template <typename T>
ins operator<<(ins x, T n)
{
	x.write1(n);
	return x;
}
ins yin;
ins yout;
#endif
int n, k, mod;
int inv2;
const int maxn = 2.5e5 + 10;
ll p[maxn], inv[maxn];
ll ksm(ll a, int n)
{
	ll ans = 1;
	while (n)
	{
		if (n & 1)ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}
// void fwt(int f[], int n, int flg)
// {
// 	for (int len = 2; len <= n; len <<= 1)
// 	{
// 		int mid = len >> 1;
// 		for (int j = 0; j < n; j += len)
// 			for (int k = 0; k <= mid; k++)
// 			{
// 				ll x = f[j], y = f[j + k];
// 				if (!flg)
// 				{
// 					f[j] = x + y;
// 					f[j + k] = x - y;
// 				}
// 				else
// 				{
// 					f[j] = (x + y) * inv2 % mod;
// 					f[j + k] = (x - y) * inv2 % mod;
// 				}
// 			}
// 	}
// }
ll f[28][maxn];
#define lowbit(x) x&-x
int main()
{
	cin >> n >> k >> mod;
	if (n & 1)
	{
		yout << ksm(k, n) << endl;
		return 0;
	}
	p[0] = 1;
	for (int i = 1; i <= n; i++)
		p[i] = p[i - 1] * i % mod;
	// cerr << p[3] << endl;
	inv[n] = ksm(p[n], mod - 2);
	for (int i = n; i; i--)
		inv[i - 1] = inv[i] * i % mod;
	f[0][0] = 1;
	for (int i = 0; i < k; i++)
	{
		for (int S = 0; S < n; S++)
		{
			if (!f[i][S])continue;
			int p = lowbit((n - S)), st = (n - S) - p;
			for (int k = st; k; k = (k - 1)&st)
			{
				(f[i + 1][S + k + p] += f[i][S] * inv[k + p] % mod) %= mod;
			}
			// cerr << i << " " << S << " " << p << " " << inv[p] << endl;
			(f[i + 1][S + p] += f[i][S] * inv[p] % mod) %= mod;
		}
	}
	ll ans = ksm(k, n);
	for (int i = 1; i <= k; i++)
		ans += mod - f[i][n] * p[k] % mod * p[n] % mod * inv[k - i] % mod;
	yout << ans % mod << endl;
	return 0;
}