// Hydro submission #632bdfd244e7d0bd860137f6@1663819731815
/*******************************
| Author:  ybw051114
| Problem: E. Ciel and Gondolas
| Contest: Codeforces Round #190 (Div. 1)
| URL:     https://codeforces.com/contest/321/problem/E
| When:    2022-09-22 11:47:56
|
| Memory:  512 MB
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
int n, k;
const int maxn = 4e3 + 10;
ll a[maxn][maxn], sum[maxn][maxn], sum1[maxn][maxn];
ll f[maxn], g[maxn];
ll calc(int l, int r)
{
	if (l > r)return 0;
	return sum1[l][r];
}
void solve(int l, int r, int ll, int rr)
{
	if (l > r)return ;
	int mid = (l + r) >> 1;
	f[mid] = 1e18;
	int pos = ll;
	for (int i = ll; i <= min(rr, mid); i++)
		if (g[i] + calc(i + 1, mid) <= f[mid])
			pos = i, f[mid] = g[i] + calc(i + 1, mid);
	solve(l, mid - 1, ll, pos);
	solve(mid + 1, r, pos, rr);
}
int main()
{
	yin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			yin >> a[i][j];
			sum[i][j] = sum[i][j - 1] + a[i][j];
		}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			sum1[i][j] = sum1[i][j - 1] + sum[j][j - 1] - sum[j][i - 1];
	// ll l = -1e7, r = 1e7;
	// while (l < r)
	// {
	// 	ll mid = (l + r) >> 1;
	// 	if (check(mid) <= k)
	// 		r = mid;
	// 	else l = mid + 1;
	// }
	// check(l);
	for (int i = 1; i <= n; i++)
		f[i] = 1e9;
	for (int i = 1; i <= k; i++)
	{
		memcpy(g, f, sizeof(f));
		solve(1, n, 0, n);
	}
	yout << f[n] << endl;
	return 0;
}