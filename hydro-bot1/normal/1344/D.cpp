// Hydro submission #6327d8ea6de4317b0a26f1d3@1663555818785
/*******************************
| Author:  ybw051114
| Problem: D. Rsum Review
| Contest: Codeforces - Codeforces Round #639 (Div. 1)
| URL:     https://codeforces.com/contest/1344/problem/D
| When:    2022-09-19 10:26:34
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
int n;
ll k, xx;
const int maxn = 1e5 + 10;
int a[maxn];
int b[maxn], id[maxn];
ll calc(ll a, ll x)
{
	if (a == x)return -4e18 - 10;
	return a - 3 * x * x - 3 * x - 1;
}
ll check(ll x)
{
	xx = 0;
	for (int i = 1; i <= n; i++)
	{
		if (calc(a[i], 0) < x)b[i] = 0;
		else
		{
			int l = 0, r = a[i] - 1;
			while (l < r)
			{
				int mid = (l + r + 1) >> 1;
				if (calc(a[i], mid) < x)r = mid - 1;
				else l = mid;
			}
			b[i] = l + 1;
		}
		xx += b[i];
	}
	return xx;
}
int main()
{
	yin >> n >> k;
	for (int i = 1; i <= n; i++)yin >> a[i];
	ll l = -4e18, r = 4e18;
	while (l < r)
	{
		ll mid = (l + r) >> 1;
		if (check(mid) <= k)r = mid;
		else l = mid + 1;
	}
	check(r);
	assert(l == r);
	// if (check(r) > k)return 0;
	for (int i = 1; i <= n; i++)
		id[i] = i;
	sort(id + 1, id + n + 1, [&](int x, int y) {return calc(a[x], b[x]) > calc(a[y], b[y]);});
	// if (k - xx > n) {if (check(l - 1) <= k)puts("!!!"); return 0;}
	for (int i = 1; i <= k - xx; i++)
		b[id[i]]++;
	for (int i = 1; i <= n; i++)yout << b[i] << " ";
	yout << endl;
	return 0;
}