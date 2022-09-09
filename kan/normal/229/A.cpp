#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 105;
const int maxm = 1e4+4;

char p[maxn][maxm];
int near[maxn][maxm];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            scanf("%c", &c);
            while (c != '0' && c != '1') scanf("%c", &c);
            p[i][j] = c;
//             cout << p[i][j];
        }
//         cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        int last = 3 * m;
        for (int j = 0, k = 0; k <= 3 * m; k++, j = (j + 1) % m)
        {
            if (p[i][j] == '1') last = 0;
            else last++;
            near[i][j] = last;
        }
        last = 3 * m;
        for (int j = n - 1, k = 0; k <= 3 * m; k++, j = (j - 1 + m) % m)
        {
            if (p[i][j] == '1') last = 0;
            else last++;
            near[i][j] = min(last, near[i][j]);
        }
        if (near[i][0] >= m)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    int answer = n * m * 2;
    for (int i = 0; i < m; i++)
    {
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            ans = ans + near[j][i];
        }
        answer = min(answer, ans);
    }
    cout << answer << endl;
	return 0;
}