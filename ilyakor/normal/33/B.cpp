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
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 200 * 1000;

char s1[maxn], s2[maxn];

int a[300][300], b[300][300];
char bc[300][300];

const int inf = 1000 * 1000 * 1000;

int main()
{
    for (int i = 0; i < 300; ++i)
        for (int j = 0; j < 300; ++j)
            b[i][j] = i == j ? 0 : inf;
    scanf("%s", s1);
    scanf("%s", s2);
    int n = strlen(s1);
    if (strlen(s2) != n)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < n; ++i)
        ++a[s1[i]][s2[i]];
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        string c1, c2;
        int w;
        cin >> c1 >> c2 >> w;
        b[c1[0]][c2[0]] = min(b[c1[0]][c2[0]], w);
    }
    for (int i = 0; i < 300; ++i)
        for (int j = 0; j < 300; ++j)
            for (int k = 0; k < 300; ++k)
                b[j][k] = min(b[j][k], b[j][i] + b[i][k]);
    int64 res = 0;
    string rs;
    for (int i = 0; i < 300; ++i)
        for (int j = 0; j < 300; ++j)
        {
            if (i == j) bc[i][j] = i;
            if (!a[i][j]) continue;
            if (i == j) continue;
            int64 cur = inf;
            char c = 0;
            for (int t = 'a'; t <= 'z'; ++t)
                if (b[i][t] + b[j][t] < cur)
                    cur = b[i][t] + b[j][t], c = t;
            if (cur >= inf)
            {
                printf("-1\n");
                return 0;
            }
            bc[i][j] = c;
            res += cur * a[i][j];
        }
    for (int i = 0; i < n; ++i)
        rs += bc[s1[i]][s2[i]];
    cout << res << "\n" << rs << "\n";
    return 0;
}