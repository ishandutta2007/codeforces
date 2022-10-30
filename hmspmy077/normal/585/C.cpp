#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <cassert>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-8;
const int inf = 100000000;

const int N = 100005;

vector<pair<long long, int> > ans;

long long gcd(long long a, long long b, int type)
{
    if (a % b == 0)
    {
        ans.pb(mp(a / b - 1, type));
        return b;
    }
    ans.pb(mp(a / b, type));
    return gcd(b, a % b, type ^ 1);
}

void work()
{
    long long a, b;
    cin >> a >> b;
    if (gcd(a, b, 0) != 1)
        cout << "Impossible" << endl;
    else
    {
        for (int i = 0; i < sz(ans); ++i)
        {
            if (ans[i].x == 0) continue;
            cout << ans[i].x << (char)(ans[i].y + 'A');
        }
    }
}

int main()
{
    #ifdef LOCAL_TEST
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    work();
    return 0;
}