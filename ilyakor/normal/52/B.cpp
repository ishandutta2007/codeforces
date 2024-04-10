#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 1010;

int n, m;
char a[maxn][maxn];
int64 h[maxn];
int64 v[maxn];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        scanf("%s", a[i]);
    for (int i = 0; i < n; ++i)
    {
        h[i] = 0;
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '*') ++h[i];
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '*')
                v[j] += h[i] - 1;
    int64 res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] != '*') continue;
            res += v[j] - h[i] + 1;
        }
    cout << res << "\n";
    return 0;
}