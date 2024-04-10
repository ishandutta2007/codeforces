// Hydro submission #631747de3f0a183d2863b856@1662470110804
/*******************************
| Author:  ybw051114
| Problem: D. Make Equal
| Contest: Codeforces - Codeforces Round #572 (Div. 1)
| URL:     https://codeforces.com/problemset/problem/1188/D
| When:    2022-09-06 20:51:23
|
| Memory:  256 MB
| Time:    4000 ms
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
const int maxn = 1e5 + 10;
int n; ll a[maxn];
ll f[65][maxn];
int k;
int cnt[2][maxn];
int main()
{
	yin >> n;
	for (int i = 1; i <= n; i++)
		yin >> a[i];
	ll mx = a[1];
	for (int i = 1; i <= n; i++)mx = max(mx, a[i]);
	for (int i = 1; i <= n; i++)a[i] = mx - a[i];
	memset(f, 0x3f3f3f3f, sizeof(f));
	f[0][0] = 0;
	for (k = 0; k < 60; k++)
	{
		ll mx = (1ll << k) - 1;
		// cerr << mx << endl;
		sort(a + 1, a + n + 1, [&](ll a, ll b) {return (a & mx) < (b & mx);});
		for (int i = 1; i <= n; i++)
		{
			cnt[0][i] = cnt[0][i - 1], cnt[1][i] = cnt[1][i - 1], cnt[a[i] >> k & 1][i] += 1;
		}
		for (int i = 0; i <= n; i++)
		{
			int nt, jj;
			nt = cnt[1][i] + cnt[0][n] - cnt[0][i], jj = cnt[1][n] - cnt[1][i];
			f[k + 1][jj] = min(f[k][n - i] + nt, f[k + 1][jj]);
			nt = cnt[0][i] + cnt[1][n] - cnt[1][i], jj = n - cnt[0][i];
			f[k + 1][jj] = min(f[k][n - i] + nt, f[k + 1][jj]);
			// cerr << k + 1 << " " << jj << ' ' << f[k + 1][jj] << " " << f[k][n - i] << " " << nt << " " << cnt[0][n] << endl;
		}
	}
	yout << f[60][0] << endl;
	return 0;
}