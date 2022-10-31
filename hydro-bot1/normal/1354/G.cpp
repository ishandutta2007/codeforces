// Hydro submission #63213361bdf9bc31d15f46a8@1663120225588
/*******************************
| Author:  ybw051114
| Problem: CF1354G Find a Gift
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/CF1354G
| When:    2022-09-14 09:25:23
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
#define eb emplace_back
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
mt19937 rnd(time(0));
int ask(vector<int> a, vector<int> b)
{
	if (a == b)return 1;
	cout << "? " << a.size() << " " << b.size() << endl;
	for (int x : a)
		cout << x << " ";
	cout << endl;
	for (int x : b)
		cout << x << " ";
	cout << endl;
	cout.flush();
	string xx;
	cin >> xx;
	if (xx[0] == 'F')return 1;
	if (xx[0] == 'S')return -1;
	if (xx[0] == 'E')return 0;
	exit(1);
}
void da(int p)
{
	cout << "! " << p << endl;
	cout.flush();
}
int check(int ll, int rr)
{
	vector<int> aa, bb;
	for (int i = 1; i <= rr - ll + 1; i++)
		aa.emplace_back(i);
	for (int i = ll; i <= rr; i++)
		bb.emplace_back(i);
	int ans = ask(aa, bb);
	return ans;
}
void solve()
{
	int n, k;
	yin >> n >> k;
	int nw = rnd() % (n - 1) + 2;
	for (int i = 1; i <= 30; i++)
	{
		int p = rnd() % (n - 1) + 2;
		int chk = ask({nw}, {p});
		if (chk == -1)
			nw = p;
	}
	int tmp = ask({nw}, {1});
	if (tmp == 1)
	{
		da(1);
		return ;
	}
	int len = 1, l = -1, r = -1;
	vector<int> cc;
	cc.emplace_back(1);
	// cerr << "!!!" << endl;
	while ((len << 1) <= n)
	{
		vector<int> a, b;
		for (int i = 1; i <= len; i++)
			a.emplace_back(i);
		for (int i = len + 1; i <= (len << 1); i++)
			b.emplace_back(i);
		int ans = ask(a, b);
		len <<= 1;
		if (ans == 0)continue;
		l = len / 2 + 1, r = len;
		break;
	}
	// cerr << "!!!" << " " << l << " " << r << endl;
	if (l == -1)
		l = len + 1, r = n;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(l, mid))
			r = mid;
		else
			l = mid + 1;
	}
	da(l);
}
int main()
{
	int TTT;
	yin >> TTT;
	while (TTT--)
		solve();
	return 0;
}