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
    int64 x, y;
    cin >> n >> y >> x;
    int64 s = 0;
    vector<int64> v(n);
    for (int i = 0; i < n - 1; ++i) {
        --x;
        v[i] = 1;
        ++s;
    }
    if (x <= 0) {
        printf("-1\n");
        return 0;
    }
    v[n - 1] = x;
    s += x * x;
    if (s < y) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < n; ++i)
        cout << v[i] << "\n";
    return 0;
}