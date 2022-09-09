#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = 200005;

char s1[maxn], s2[maxn];

void mysort(char *b, char *e)
{
    if ((e - b) % 2 == 1) return;
    int len = (e - b) / 2;
    char *mid = b + len;
    mysort(b, mid);
    mysort(mid, e);
    for (int i = 0; i < len; i++) if (b[i] != mid[i])
    {
        if (b[i] > mid[i]) rotate(b, mid, e);
        return;
    }
}

int main()
{
    scanf("%s%s", s1, s2);
    int n = strlen(s1);
    mysort(s1, s1 + n);
    mysort(s2, s2 + n);
    if (strcmp(s1, s2) == 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}