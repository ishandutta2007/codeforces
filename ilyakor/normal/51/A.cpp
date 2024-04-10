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

int main()
{
    int n;
    cin >> n;
    vector<vi> v;
    char ts[10];
    for (int i = 0; i < n; ++i)
    {
        if (i) scanf("%s", ts);
        vi cur(4);
        scanf("%s", ts);
        cur[0] = ts[0] - '0';
        cur[1] = ts[1] - '0';
        scanf("%s", ts);
        cur[2] = ts[1] - '0';
        cur[3] = ts[0] - '0';
        bool ok = true;
        for (int j = 0; j < sz(v); ++j)
        {
            for (int t = 0; t < 4; ++t)
            {
                rotate(cur.begin(), cur.begin() + 1, cur.end());
                if (v[j] == cur)
                {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) v.pb(cur);
    }
    cout << sz(v) << "\n";
    return 0;
}