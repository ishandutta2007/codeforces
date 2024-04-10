#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 200;
char S[MAXN + 10];
int Cnt[26 + 10];

int main()
{
	int n, tot = 0, ans = 0;
	scanf("%d", &n);
	scanf("%s", S);
	memset(Cnt, 0, sizeof(int) * 26);
	for(int i = 0; i < n; i++)
	{
		if('A' <= S[i] && S[i] <= 'Z')
		{
			memset(Cnt, 0, sizeof(int) * 26);
			if(tot > ans)
				ans = tot;
			tot = 0;
		}
		else if('a' <= S[i] && S[i] <= 'z')
			if(Cnt[S[i] - 'a']++ == 0)
				tot++;
	}
	printf("%d\n", max(tot, ans));
	return 0;
}