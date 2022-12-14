#include <bits/stdc++.h>
using namespace std;

using r32 = double;

const int MaxN = 5000;
const int NLet = 26;

string s;
vector<int> pos[NLet];

int main()
{
	cin >> s;

	int n = s.length();
	for (int i = 0; i < n; ++i)
		pos[s[i] - 'a'].push_back(i);

	int res = 0;
	for (int i = 0; i < NLet; ++i)
	{
		int v = 0;
		for (int d = 0; d < n; ++d)
		{
			vector<int> f(26, 0);
			for (int k : pos[i])
				++f[s[(k + d) % n] - 'a'];

			v = max(v, (int)count(f.begin(), f.end(), 1));
		}

		res += v;
	}

	printf("%.16f\n", (r32)res / n);

	return 0;
}