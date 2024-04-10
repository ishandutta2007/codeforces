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
        scanf("%d", &v[i]);
    int64 res = 0;
    int64 cur = 1;
    for (int i = 1; i < n; ++i) {
        if (v[i] == v[i - 1]) {
            ++cur;
            continue;
        }
        res += cur * (cur + 1LL) / 2LL;
        cur = 1;
    }
    res += cur * (cur + 1LL) / 2LL;
    cout << res << "\n";
    return 0;
}