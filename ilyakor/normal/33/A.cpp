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
#define mp make_pair
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
    int n, m, k;
    cin >> n >> m >> k;
    vi v(m, 1000 * 1000 * 1000);
    for (int i = 0; i < n; ++i)
    {
        int r, c;
        cin >> r >> c;
        r--;
        v[r] = min(v[r], c);
    }
    int res = 0;
    for (int i = 0; i < m; ++i)
        res += v[i];
    res = min(res, k);
    cout << res << "\n";
    return 0;
}