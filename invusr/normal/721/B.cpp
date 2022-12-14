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

const int MaxN = 105;

int n, k;
string s[MaxN];
string pw;

inline bool comp(string a, string b)
{
	return a.size() < b.size();
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> s[i];
	cin >> pw;

	sort(s + 1, s + n + 1, comp);

	int cntL = 0, cntE = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (s[i].size() < pw.size())
			++cntL;
		if (s[i].size() <= pw.size())
			++cntE;
	}
	--cntE;

	cout << cntL + cntL / k * 5 + 1 << ' ';
	cout << cntE + cntE / k * 5 + 1;

	return 0;
}