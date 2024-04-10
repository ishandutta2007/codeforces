#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

int d[100][100];
int k;

int solve(int n, int m)
{
    if (k == 1)
        return n % 2 == 1 || m % 2 == 1 ? 1 : 0;
    int r = min(n / (2 * k + 2), m / (2 * k + 2));
    n -= r * (2 * k + 2);
    m -= r * (2 * k + 2);
    if (n < k || m < k)
        return (n % 2 + m % 2) % 2;
    if (n == k || m == k)
        return 1;
    if (n == 2 * k + 1 && m >= 2 * k + 1)
        return 1;
    if (m == 2 * k + 1 && n >= 2 * k + 1)
        return 1;
    return (n % 2 + m % 2 + 1) % 2;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nc;
    cin >> nc >> k;
    /*for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            d[i][j] = 0;
            if (i && !d[i - 1][j])
                d[i][j] = 1;
            if (j && !d[i][j - 1])
                d[i][j] = 1;
            if (i >= k && j >= k && !d[i - k][j - k])
                d[i][j] = 1;
            printf("%d", d[i][j]);
            //if (i >= 2 * k + 2 && j >= 2 * k + 2 && d[i][j] != d[i - 2 * k - 2][j - 2 * k - 2])
            if (d[i][j] != solve(i, j))
                cerr << "Botva " << i << " " << j << "\n";
        }
        printf("\n");
    }*/
//  k++;
    for (int it = 0; it < nc; ++it)
    {
        int n, m;
        cin >> n >> m;
        n--, m--;
        printf("%c\n", solve(n, m) ? '+' : '-');
    }
    return 0;
}