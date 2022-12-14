#include <bits/stdc++.h>
using namespace std;

typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

typedef double r32;
typedef long double r64;

template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tense(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

const s64 INF = 0x3f3f3f3f3f3f3f3fll;

char s[11111];
int p, m, k;

struct info
{
	s64 f[101], g[101];
	int n;
};

void merge(info &a, info b)
{
	info c;
	c.n = min(k, a.n + b.n + 1);

	fill(c.f, c.f + c.n + 1, -INF);
	fill(c.g, c.g + c.n + 1, INF);

	for (int i = 0; i <= a.n; ++i)
		for (int j = 0; j <= b.n; ++j)
			for (int l = 0; l < 2; ++l)
			{
				int s = i + j + l;
				if (s > c.n)
					break;

				s64 vf = ((p < m) == l) ? b.f[j] : -b.g[j];
				s64 vg = ((p < m) == l) ? b.g[j] : -b.f[j];
				relax(c.f[s], a.f[i] + vf);
				tense(c.g[s], a.g[i] + vg);
			}

	a = c;
}

int lk[11111];

info solve(int l, int r)
{
//	cout << l << ' ' << r << endl;
//	system("pause>nul");
	info a;

	bool flag = false;
	bool vis = false;

	s64 cur = 0;
	for (int i = l; i <= r; ++i)
	{
		if (s[i] == '(')
		{
			if (i == l)
				continue;

			int nx = lk[i];
			info b = solve(i, nx);
			i = nx;

			if (flag)
				merge(a, b);
			else
				a = b;

			flag = true;
		}
		else if (isdigit(s[i]))
		{
			cur = cur * 10 + s[i] - '0';
			vis = true;
		}
		else if (s[i] == '?')
		{
			if (!vis)
				continue;

			info b;
			b.n = 0;
			b.f[0] = b.g[0] = cur;
			cur = 0, vis = false;

			if (flag)
				merge(a, b);
			else
				a = b;

			flag = true;

		//	cout << a.f[0] << endl;
		}
	}

	if (vis)
	{
		info b;
		b.n = 0;
		b.f[0] = b.g[0] = cur;
		cur = 0;

		if (flag)
			merge(a, b);
		else
			a = b;

	//	cout << a.f[0] << endl;
	}

	return a;
}



int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> s + 1;
	cin >> p >> m, k = min(p, m);

	int n = strlen(s + 1);

	stack<int> st;
	for (int i = 1; i <= n; ++i)
	{
		if (s[i] == '(')
			st.push(i);
		else if (s[i] == ')')
		{
			lk[st.top()] = i;
			st.pop();
		}
	}

	cout << solve(1 + (s[1] == '('), n - (s[n] == ')')).f[k] << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}