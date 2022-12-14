#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int MaxN = 2000;
const int NLet = 26;

int n;
char s[MaxN + 2], t[MaxN + 2];
char p[MaxN + 2];

vector<int> result;

inline void shift(int x)
{
	result.push_back(x);

	int k = 0;
	for (int i = 0; i < x; ++i)
		p[++k] = s[n - i];
	for (int i = 1; i <= n - x; ++i)
		p[++k] = s[i];
	for (int i = 1; i <= n; ++i)
		s[i] = p[i];
}

int main()
{
	cin >> n;
	cin >> s + 1;
	cin >> t + 1;

	for (int i = 0; i < NLet; ++i)
	{
		int a = count(s + 1, s + n + 1, 'a' + i);
		int b = count(t + 1, t + n + 1, 'a' + i);
		if (a != b)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		shift(n);

		int k = n - i + 1;
		for (int j = 1; j <= k; ++j)
			if (s[j] == t[k])
			{
				shift(n - j);
				break;
			}

		shift(1);
	}

	cout << result.size() << endl;
	for (int i : result)
		cout << i << ' ';
	cout << endl;

	return 0;
}