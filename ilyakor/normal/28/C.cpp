#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 57;

int n, m;
int a[maxn];

double d[maxn][maxn][maxn];
double mpow[maxn];

double C[maxn + 2][maxn + 2];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    mpow[0] = 1.0;
    for (int i = 1; i < maxn; i++)
        mpow[i] = mpow[i - 1] / m;
    C[0][0] = 1.0;
    for (int i = 1; i < maxn; i++)
    {
        C[i][0] = 1.0;
        for (int j = 1; j < maxn; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    d[0][0][0] = 1.0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
            {
                for (int t = 0; j + t <= n; t++)
                {
                    int nk = max(k, (t / a[i]) + (t % a[i] ? 1 : 0));
                    d[i + 1][j + t][nk] += d[i][j][k] * C[n - j][t] * mpow[t];
                }
            }
    double res = 0.0;
    for (int i = 0; i <= n; i++)
        res += d[m][n][i] * (i + 0.0);
    printf("%.20lf\n", res);
    return 0;
}