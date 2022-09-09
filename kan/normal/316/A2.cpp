#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

char s[200005];
bool used[20];

int main()
{
	scanf("%s", s);
	int n = strlen(s);
	int kempty = 10;
	int kz = 0;
	int answer = 1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '?')
		{
			if (i == 0) answer *= 9;
			else kz++;
		}
		if (s[i] >= 'A' && s[i] <= 'J' && !used[s[i] - 'A'])
		{
			used[s[i] - 'A'] = true;
			if (i == 0) answer *= 9;
			else answer *= kempty;
			kempty--;
		}
	}
	printf("%d", answer);
	for (int i = 0; i < kz; i++) printf("0");
	printf("\n");
	return 0;
}