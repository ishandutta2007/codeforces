#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second

bool was[205][205][205];
int ans[205][205][205];
int n;
char s[205];

int go(int i, int j, int t)
{
    if (i == 1 && j == 0 && t == 0) return 1;
    if (i == 0 && j == 1 && t == 0) return 2;
    if (i == 0 && j == 0 && t == 1) return 4;
    if (was[i][j][t]) return ans[i][j][t];
    was[i][j][t] = true;
    int &a = ans[i][j][t];
    if (i >= 2) ans[i][j][t] |= go(i - 1, j, t);
    if (j >= 2) ans[i][j][t] |= go(i, j - 1, t);
    if (t >= 2) ans[i][j][t] |= go(i ,j ,t - 1);
    if (i && j) a |= go(i - 1, j - 1, t + 1);
    if (t && j) a |= go(i + 1, j - 1, t - 1);
    if (i && t) a |= go(i - 1, j + 1, t - 1);
    return a;
}

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    int kr = 0, kg = 0, kb = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R') kr++;
        if (s[i] == 'B') kb++;
        if (s[i] == 'G') kg++;
    }
    int ans = go(kr, kg, kb);
    if (ans & 4) cout << 'B';
    if (ans & 2) cout << 'G';
    if (ans & 1) cout << 'R';
    cout << endl;
    return 0;
}