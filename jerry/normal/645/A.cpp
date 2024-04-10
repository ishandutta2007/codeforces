#include <bits/stdc++.h>
using namespace std;

string foo()
{
	char a[6]; string ans;
	scanf("%s", a);
	ans += a;
	scanf("%s", a);
	reverse(a, a+2);
	ans += a;
	string ret;
	for (char c: ans) if (c != 'X') ret += c;
	return ret;
}

int main()
{
	string a = foo(); string b = foo();
	for (int i = 0;i < 10;i++)
	{
		string c = a; c.pop_back(); c = a.back() + c;
		if (c == b)
		{
			printf("YES\n");
			return 0;
		}
		a = c;
	}
	printf("NO\n");
	return 0;
}