#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	const int MAXN = 200000;
	char S[MAXN + 1];

	void work()
	{
		int n, s = 0, mx = 0;
		scanf("%d%s", &n, S);
		for (int i = 0; i < n; i++)
		{
			if (S[i] == '(')
				s++;
			else
				s--;
			if (s < mx)
				mx = s;
		}
		puts(!s && mx >= -1 ? "Yes" : "No");
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}