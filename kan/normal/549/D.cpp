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

const int maxn = 105;

char p[maxn][maxn];
int coef[maxn][maxn];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
//     n = 100;
//     m = 100;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", p[i]);
//         for (int j = 0; j < m; j++) p[i][j] = ((i + j) % 2 == 0 ? 'W' : 'B');
    }
    int answer = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int need = (p[i][j] == 'B' ? -1 : 1);
            if (need != coef[i][j])
            {
                answer ++;
                int add = need - coef[i][j];
                for (int ii = 0; ii <= i; ii++)
                {
                    for (int jj = 0; jj <= j; jj++) coef[ii][jj] += add;
                }
            }
        }
    }
    cout << answer <<endl;
	return 0;
}