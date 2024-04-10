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

bool cross(int x1, int y1, int x2, int y2)
{
    return max(x1, x2) < min(y1, y2);
}

int main()
{
    int n, t;
    cin >> n >> t;
    vi L(n), R(n);
    vi v;
    for (int i = 0; i < n; i++)
    {
        int x, a;
        cin >> x >> a;
        x *= 2;
        L[i] = x - a, R[i] = x + a;
        v.pb(x - a - t);
        v.pb(x + a + t);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int res = 0;
    for (int i = 0; i < sz(v); i++)
    {
        bool ok = true;
        for (int j = 0; j < n; j++)
            if (cross(L[j], R[j], v[i] - t, v[i] + t))
            {
                ok = false;
                break;
            }
        if (ok) res++;
    }
    cout << res << "\n";
    return 0;
}