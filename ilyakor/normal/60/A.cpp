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
    int n, m;
    cin >> n >> m;
    vi u(n + 1, 0);
    for (int it = 0; it < m; ++it) {
        string a, b, c, d;
        int e;
        cin >> a >> b >> c >> d >> e;
        int l, r;
        if (c == "left")
            l = e, r = n;
        else
            l = 1, r = e;
        for (int i = l; i <= r; ++i)
            u[i] = 1;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (!u[i]) ++res;
    if (res == 0) res = -1;
    cout << res << "\n";
    return 0;
}