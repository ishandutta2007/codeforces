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
    int n, m, k;
    bool ok = true;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (x - 1 < 5 || y - 1 < 5 || n - x < 5 || m - y < 5)
        {
            ok = false;
            break;
        }
    }
    printf("%s\n", !ok ? "YES" : "NO");
    return 0;
}