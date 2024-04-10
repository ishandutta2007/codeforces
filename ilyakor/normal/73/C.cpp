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

string s;
int k;

const int maxn = 110;
const int inf = 1000 * 1000 * 100;

int d[maxn][maxn][27];

int a[27][27];

int main()
{
    cin >> s >> k;
    int m;
    cin >> m;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < m; ++i) {
        string s1, s2;
        int x;
        cin >> s1 >> s2 >> x;
        a[s1[0] - 'a'][s2[0] - 'a'] += x;
    }
    int n = sz(s);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
            for (int c = 0; c < 27; ++c)
                d[i][j][c] = -inf;
    d[0][0][26] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= k; ++j)
            for (int c = 0; c < 27; ++c) {
                if (d[i][j][c] == -inf) continue;
                d[i + 1][j][s[i] - 'a'] = max(d[i + 1][j][s[i] - 'a'], d[i][j][c] + a[c][s[i] - 'a']);
                for (int cc = 0; cc < 26; ++cc) 
                    d[i + 1][j + 1][cc] = max(d[i + 1][j + 1][cc], d[i][j][c] + a[c][cc]);
            }
    int res = -inf;
    for (int i = 0; i <= k; ++i)
        for (int j = 0; j < 26; ++j)
            res = max(res, d[n][i][j]);
    cout << res << "\n";
    return 0;
}