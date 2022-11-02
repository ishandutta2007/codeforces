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

char buf[2 * 100500];

vi a[300];

int main()
{
    int n, k;
    cin >> n >> k;
    scanf("%s", buf);
    for (int i = 0; buf[i]; ++i)
        a[buf[i]].pb(i);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", buf);
        int64 res = 0;
        int l = strlen(buf);
        for (int i = 0; buf[i]; ++i) {
            char c = buf[i];
            vi& v = a[c];
            int ind = lower_bound(all(v), i) - v.begin();
            int cur = 1000 * 1000 * 1000;
            for (int j = -2; j <= 2; ++j) {
                int x = ind + j;
                if (x < 0 || x >= sz(v)) continue;
                cur = min(cur, abs(v[x] - i));
            }
            if (cur == 1000 * 1000 * 1000)
                cur = l;
            res += cur;
        }
        cout << res << "\n";
    }
    return 0;
}