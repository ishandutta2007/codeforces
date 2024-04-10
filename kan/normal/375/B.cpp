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

const int maxn = 5005;

int kv[maxn][maxn];
char s[maxn];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        s[m] = '0';
        for (int j = 0; j < m; j++) if (s[j] == '1')
        {
            int was = j;
            while (s[j] == '1') j++;
            kv[was][j - 1]++;
        }
    }
    int answer = 0;
    for (int len = m; len > 0; len--)
    {
        for (int i = 0; i + len - 1 < m; i++)
        {
            int j = i + len - 1;
            if (i > 0) kv[i][j] += kv[i - 1][j] - kv[i - 1][j + 1];
            kv[i][j] += kv[i][j + 1];
            answer = max(answer, len * kv[i][j]);
        }
    }
    cout << answer << endl;
	return 0;
}