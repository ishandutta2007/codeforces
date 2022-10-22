#include <bits/stdc++.h>

using namespace std;

const int L = 20000;

int main()
{
	int n, x = 0;
	cin >> n;
	while(n--)
	{
		int v;
		string d;
		cin >> v >> d;
		if(x == 0)
		{
			if(d != "South")
				goto fail;
		}
		else if(x == L)
		{
			if(d != "North")
				goto fail;
		}
		if(d == "North")
			x -= v;
		else if(d == "South")
			x += v;
		if(x < 0 || x > L)
			goto fail;
	}
	if(x != 0)
		goto fail;
	puts("YES");
	return 0;
fail:
	puts("NO");
	return 0;
}