#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 100005;

char s[maxn];
int ans[30];
int n, m;

void ttry(int b)
{
	int last = -1;
	int lastc = -1;
	for (int i = 0; i < 26; i++) ans[i] = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] - 'a' < b)
		{
			last = i;
			ans[s[i] - 'a']++;
			continue;
		}
		if (s[i] - 'a' == b)
		{
			lastc = i;
		}
		if (i - last == m)
		{
			if (lastc <= last) return;
			ans[b]++;
			last = lastc;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < ans[i]; j++) printf("%c", 'a' + i);
	}
	printf("\n");
	exit(0);
}

int main()
{
	scanf("%d", &m);
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < 26; i++) ttry(i);
	return 0;
}