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

int n;
char s[MaxN];

vector<int> res;

int main()
{
	scanf("%d%s", &n, s + 1);
	s[0] = 'W';
	s[n + 1] = 'W';

	for (int i = 1, j; i <= n; i = j + 1)
	{
		j = i;
		if (s[i] == 'B')
		{
			while (s[j + 1] == 'B')
				++j;
			res.push_back(j - i + 1);
		}
	}

	printf("%d\n", res.size());
	for (int i: res)
		printf("%d ", i);

	return 0;
}