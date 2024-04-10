// Hydro submission #6321599fbdf9bc31d15f61f4@1663130015358
/*******************************
| Author:  ybw051114
| Problem: CF1325E Ehab's REAL Number Theory Problem
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/CF1325E
| When:    2022-09-14 12:14:29
|
| Memory:  250 MB
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
int n;
int ans;
const int maxn = 1e6 + 10;
vector<pair<int, int> > e[maxn];
int mp[maxn];
int tot, cnt;
void ad(int u, int v)
{
	if (!mp[u])mp[u] = ++tot;
	if (!mp[v])mp[v] = ++tot;
	++cnt;
	e[mp[u]].emplace_back(mp[v], cnt);
	e[mp[v]].emplace_back(mp[u], cnt);
}
void add(int x)
{
	vector<int> cx;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
		{
			while (x % (i * i) == 0)
				x /= i * i;
			if (x % i == 0)
				cx.emplace_back(i), x /= i;
		}
	if (x > 1)cx.emplace_back(x);
	if (cx.size() == 2)ad(cx[0], cx[1]);
	else if (cx.size() == 1)ad(1, cx[0]);
	else
	{
		puts("1");
		exit(0);
	}
}
int dis[maxn];
int main()
{
	yin >> n;
	ans = n + 1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		yin >> x;
		add(x);
	}
	for (int i = 1; i <= 1000; i++)
		if (mp[i])
		{
			memset(dis, 0, sizeof(int[tot + 1]));
			queue<pair<int, int>>q ;
			q.push({mp[i], 0});
			dis[mp[i]] = 1;
			while (!q.empty())
			{
				auto  [u, ff] = q.front();
				q.pop();
				for (auto [v, e] : e[u])
					if (!dis[v])
						dis[v] = dis[u] + 1, q.push({v, e});
					else
					{
						if (e != ff)
							ans = min(ans, dis[v] + dis[u] - 1);
					}
			}
		}
	if (ans == n + 1)yout << -1 << endl;
	else
		yout << ans << endl;
	return 0;
}