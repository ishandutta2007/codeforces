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

const int maxn = 105;

int a[maxn];
char s[205];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		scanf(" %[^\n]", s);
		int l = strlen(s);
		int k = 0;
		for (int j = 0; j < l; j++) if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y') k++;
		if (k != a[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}