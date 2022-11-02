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

const int maxn = 2 * 1000 * 1000;

int64 MOD = 218405757LL;

int a[maxn];
int64 h[maxn + 10];
int64 pw[maxn + 10];

int64 get(int l, int r)
{
    int64 res = h[r + 1] - h[l] * pw[r - l + 1];
    return res;
}

map<int, vi> M;
int n;

vector<ii> v;

void check(int ind)
{
    if (!ind)
        return;
    vi& v = M[a[ind]];
    for (int i = 0; i < sz(v); i++)
    {
        int x = v[i];
        if (x >= ind) continue;
        if (ind - x > n - ind) continue;
        if (get(x, ind - 1) == get(ind, 2 * ind - x - 1))
        {
            (::v).pb(ii(ind - x, ind));
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        M[a[i]].pb(i);
    }
    h[0] = 0;
    for (int i = 0; i < n; i++)
        h[i + 1] = h[i] * MOD + a[i];
    pw[0] = 1;
    for (int i = 0; i < maxn; i++)
        pw[i + 1] = pw[i] * MOD;
    for (int i = n - 1; i >= 0; i--)
    {
        check(i);
    }
    int res =  0;
    sort(all(v));
    for (int i = 0; i < sz(v); i++)
    {
        if (v[i].second - v[i].first < res) continue;
        res = v[i].second;
    }
    printf("%d\n", n - res);
    for (int j = res; j < n; j++)
        printf("%d ", a[j]);
    printf("\n");
    return 0;
}