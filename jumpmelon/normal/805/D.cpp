#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000, P = 1000000007;
char S[MAXN + 10];

int main()
{
	int n, tot = 0, cur = 0;
	scanf("%s", S);
	n = strlen(S);
	for(int i = n - 1; i >= 0; i--)
		if(S[i] == 'b')
			cur = (cur + 1) % P;
		else if(S[i] == 'a')
		{
			tot = (tot + cur) % P;
			cur = (cur << 1) % P;
		}
	printf("%d\n", tot);
	return 0;
}