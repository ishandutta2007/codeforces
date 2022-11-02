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
    vi v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int res = 1;
    for (int i = 0; i < n; ++i) {
        int cur = 1;
        {
            int x = i - 1;
            while (x >= 0 && v[x] <= v[x + 1]) ++cur, --x;
        }
        {
            int x = i + 1;
            while (x < sz(v) && v[x] <= v[x - 1]) ++cur, ++x;
        }
        res = max(res, cur);
    }
    cout << res << "\n";
    return 0;
}