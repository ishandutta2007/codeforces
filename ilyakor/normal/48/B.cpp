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

int A[57][57];

int n, m, a, b;

int calc(int x, int y)
{
    int res = 1000 * 1000 * 1000;
    for (int i = 0; i + x <= n; ++i)
        for (int j = 0; j + y <= m; ++j)
        {
            int cur = 0;
            for (int p = 0; p < x; ++p)
                for (int q = 0; q < y; ++q)
                    cur += A[i + p][j + q];
            res = min(res, cur);
        }
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &A[i][j]);
    cin >> a >> b;
    cout << min(calc(a, b), calc(b, a)) << "\n";
    return 0;
}