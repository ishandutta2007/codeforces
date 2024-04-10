#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	typedef pair<int, int> pii;
	const int N = 5e5 + 5;

	char s[N];

	void work()
	{
		scanf("%s", s + 1);
		int n = strlen(s + 1), mn = 26;
		for (int i = 1; i <= n; i++)
		{
			int c = s[i] - 'a';
			puts(mn < c ? "Ann" : "Mike");
			mn = min(mn, c);
		}
	}
}

int main()
{
	TYC::work();
	return 0;
}