#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	n *= m;

	bool ok = true;
	while (n--)
	{
		char c;
		while ((c = getchar()) < 'A' || c > 'Z');
		if (c == 'C' || c == 'M' || c == 'Y')
			ok = false;
	}

	if (ok)
		puts("#Black&White");
	else
		puts("#Color");

	return 0;
}