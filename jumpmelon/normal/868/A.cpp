#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char S[10], T[10];

int main()
{
	int n;
	bool f0 = 0, f1 = 0;
	scanf("%s", S);
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", T);
		if(S[0] == T[0] && S[1] == T[1])
		{
			puts("YES");
			return 0;
		}
		if(S[0] == T[1])
			f0 = 1;
		if(S[1] == T[0])
			f1 = 1;
	}
	if(f0 && f1)
		puts("YES");
	else
		puts("NO");
	return 0;
}