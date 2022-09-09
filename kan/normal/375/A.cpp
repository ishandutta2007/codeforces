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

const int maxn = 1000006;

char s[maxn];
int kv[20];

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) kv[s[i] - '0']++;
    kv[1]--;
    kv[6]--;
    kv[8]--;
    kv[9]--;
    int curost = 0;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < kv[i]; j++)
        {
            printf("%d", i);
            curost = (curost * 10 + i) % 7;
        }
    }
    s[0] = '1';
    s[1] = '6';
    s[2] = '8';
    s[3] = '9';
    s[4] = 0;
    curost = (curost * 10000) % 7;
    while (true)
    {
        int cur;
        sscanf(s, "%d", &cur);
        if ((cur + curost) % 7 == 0)
        {
            printf("%s", s);
            break;
        }
        assert(next_permutation(s, s + 4));
    }
    for (int i = 0; i < kv[0]; i++) printf("0");
    printf("\n");
	return 0;
}