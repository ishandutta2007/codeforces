// Hydro submission #6321183832ae6c3198ca74b2@1663113273326
/*******************************
| Author:  ybw051114
| Problem: CF1615F LEGOndary Grandmaster
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/CF1615F
| When:    2022-09-14 07:39:01
|
| Memory:  500 MB
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
const int maxn = 2e3 + 10;
unordered_map<int, int> f[maxn], suf[maxn];
const int mod = 1e9 + 7;
int main()
{
	int TTT;
	yin >> TTT;
	while (TTT--)
	{
		string s, t;
		int n;
		yin >> n;
		yin >> s >> t;
		for (int i = 0; i < n; i++)
			if (i & 1)
			{
				if (s[i] == '1')
					s[i] = '0';
				else if (s[i] == '0') s[i] = '1';
			}
		for (int i = 0; i < n; i++)
			if (i & 1)
			{
				if (t[i] == '1')
					t[i] = '0';
				else if (t[i] == '0') t[i] = '1';
			}
		f[0].clear(); f[0][0] = 1;
		for (int i = 0; i < n; i++)
		{
			f[i + 1].clear();
			for (auto x : f[i])
			{
				for (int a = 0; a < 2; a++)
					for (int b = 0; b < 2; b++)
					{
						if (s[i] != '?' && a != s[i] - '0')
							continue;
						if (t[i] != '?' && b != t[i] - '0')
							continue;
						(f[i + 1][x.first + a - b] += x.second) %= mod;
					}
			}
		}
		suf[n].clear(); suf[n][0] = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			suf[i].clear();
			for (auto x : suf[i + 1])
			{
				for (int a = 0; a < 2; a++)
					for (int b = 0; b < 2; b++)
					{
						if (s[i] != '?' && a != s[i] - '0')
							continue;
						if (t[i] != '?' && b != t[i] - '0')
							continue;
						// cerr << x.first << " " << a << " " << b << " " << s[i] << " " << t[i] << endl;
						(suf[i ][x.first + a - b] += x.second) %= mod;
					}
			}
		}
		ll ans = 0;
		for (int i = 1; i < n; i++)
			for (int j = -i; j <= i; j++)
				(ans += (1ll * f[i][j] * abs(j) % mod * suf[i][-j] % mod)) %= mod;
		yout << ans << endl;
	}
	return 0;
}