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

template<class T> T sqr(T x) {return x * x;}

int X[100], Y[100];

int g[30][30];
int d[1 << 24];
int f[1 << 24];

int n;

int dfs(int mask)
{
    int& res = d[mask];
    if (res != -1) return res;
    int l = -1;
    for (int i = 0; i < n; i++)
        if ((mask >> i) & 1)
        {
            l = i;
            break;
        }
    if (l == -1) return res = 0;
    res = g[l][l] + dfs(mask ^ (1 << l));
    f[mask] = mask ^ (1 << l);
    for (int i = l + 1; i < n; i++)
    {
        if ((mask >> i) & 1)
        {
            int nm = mask ^ (1 << l) ^ (1 << i);
            int cur = g[l][i] + dfs(nm);
            if (cur < res)
                res = cur, f[mask] = nm;
        }
    }
    return res;
}

void restore(int mask)
{
    if (mask == 0) return;
    int nm = f[mask];
    int dif = mask ^ nm;
    for (int i = 0; i < n; i++)
        if ((dif >> i) & 1)
            printf("%d ", i + 1);
    printf("0 ");
    restore(nm);
}

int main()
{
    memset(d, -1, sizeof(d));
    int xs, ys;
    cin >> xs >> ys;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> X[i] >> Y[i];
        X[i] -= xs, Y[i] -= ys;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]) + sqr(X[i]) + sqr(Y[i]) + sqr(X[j]) + sqr(Y[j]);
    int res = dfs((1 << n) - 1);
    cout << res << "\n0 ";
    restore((1 << n) - 1);
    printf("\n");
    return 0;
}