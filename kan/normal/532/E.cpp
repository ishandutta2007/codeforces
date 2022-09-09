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

const int maxn = 100005;

char s1[maxn], s2[maxn];
int answer;
int n;

void check(char *s1, char *s2, int first, int last)
{
    bool ok = true;
    for (int i = first + 1; i <= last; i++) if (s1[i] != s2[i - 1]) ok = false;
    answer += ok;
}

int main()
{
    scanf("%d", &n);
    scanf("%s%s", s1, s2);
    int first = -1;
    int last = -1;
    for (int i = 0; i < n; i++) if (s1[i] != s2[i])
    {
        first = i;
        break;
    }
    for (int i = n - 1; i >= 0; i--) if (s1[i] != s2[i])
    {
        last = i;
        break;
    }
    answer = 0;
    check(s1, s2, first, last);
    check(s2, s1, first, last);
    cout << answer << endl;
    return 0;
}