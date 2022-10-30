// Hydro submission #631610c665233124267c9ba2@1662390470898
/*******************************
| Author:  ybw051114
| Problem: CF1476F Lanterns
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/CF1476F
| When:    2022-09-05 22:52:00
|
| Memory:  250 MB
| Time:    2000 ms
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
const int maxn = 3e5 + 10;
int n, p[maxn];
int cc[22][maxn];
int f[maxn], lg[maxn];
int lst[maxn], xx[maxn];
int qq(int l, int r)
{
	if (l > r)return 0;
	int k = lg[r - l + 1];
	return max(cc[k][l], cc[k][r - (1 << k) + 1]);
}
void out(int p)
{
	// cerr << p << endl;
	if (!p)return;
	out(lst[p]);
	if (!xx[p])yout << 'R';
	else
	{
		for (int i = lst[p] + 1; i < p; i++)
			yout << 'R';
		yout << 'L';
	}
}
void solve()
{
	yin >> n;
	for (int i = 1; i <= n; i++)
		yin >> p[i], cc[0][i] = i + p[i];
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= n - (1 << i); j++)
			cc[i][j] = max(cc[i - 1][j], cc[i - 1][j + (1 << (i - 1))]);
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i >> 1] + 1;
	// f[1] = lst[1] = xx[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		f[i] = f[i - 1];
		if (f[i - 1] >= i)f[i] = max(f[i], i + p[i]);
		lst[i] = i - 1, xx[i] = 0;
		int t = lower_bound(f, f + i , i - p[i] - 1) - f;
		// yout << i << " " << t << " " << f[i] << endl;
		if (t >= i)continue;
		int c = max(i - 1, qq(t + 1, i - 1));
		if (c >= f[i])
			f[i] = c, lst[i] = t, xx[i] = 1;
	}
	// cerr << f[n] << " " << n << endl;
	if (f[n] >= n)
	{
		puts("Yes");
		out(n);
		yout << endl;
	}
	else puts("No");
}
int main()
{
	int TTT;
	yin >> TTT;
	while (TTT--)solve();
	return 0;
}