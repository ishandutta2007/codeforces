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

vector<ii> g[1000];

int main()
{
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].pb(ii(y, 0));
        g[y].pb(ii(x, z));
        s += z;
    }
    int res = 0;
    int cur = 1;
    int prev = -1;
    do
    {
        for (int i = 0; i < sz(g[cur]); i++)
            if (g[cur][i].first != prev)
            {
                prev = cur;
                res += g[cur][i].second;
                cur = g[cur][i].first;
                break;
            }
    }
    while (cur != 1);
    res = min(res, s - res);
    cout << res << "\n";
    return 0;
}