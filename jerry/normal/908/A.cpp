#include <bits/stdc++.h>
using namespace std;

char buf[64];
int ans;

bool isVowel(char x)
{
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

bool isOdd(char x)
{
	return x == '1' || x == '3' || x == '5' || x == '7' || x == '9';
}

int main()
{
	scanf("%s", buf);
	for (int i = 0;buf[i];i++)
	{
		if (isVowel(buf[i])) ans++;
		else if (isOdd(buf[i])) ans++;
	}
	printf("%d\n", ans);
	return 0;
}