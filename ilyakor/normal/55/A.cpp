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

const int maxn = 1100;

bool u[maxn][maxn];

bool vis[maxn];

int main()
{
    int n;
    cin >> n;
    int cur = 0, ct = 1;
    while (1)
    {
        cur %= n;
        ct %= n;
        if (u[cur][ct]) break;
        u[cur][ct] = true;
        vis[cur] = true;
        cur += ct;
        ++ct;
    }
    bool ok = true;
    for (int i = 0; i < n; ++i)
        if (!vis[i]) ok = false;
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}