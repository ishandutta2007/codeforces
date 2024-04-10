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

int a[10][10];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        char ts[100];
        scanf("%s", ts);
        for (int j = 0; j < n; ++j)
            a[i][j] = ts[j] == '*';
    }
    int m = 1;
    for (int i = 0; i < k; ++i)
        m *= n;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int x = i, y = j;
            bool fl = false;
            for (int t = 0; t < k; ++t)
            {
                if (a[x % n][y % n])
                {
                    fl = true;
                    break;
                }
                x /= n;
                y /= n;
            }
            printf("%c", fl ? '*' : '.');
        }
        printf("\n");
    }
    return 0;
}