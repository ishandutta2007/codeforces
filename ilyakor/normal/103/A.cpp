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
    vector<int64> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    //sort(all(v));
    //reverse(all(v));
    int64 res = 0;
    for (int i = 0; i < sz(v); ++i) {
        res += 1LL;
        res += (i + 1LL) * (v[i] - 1LL);
    }
    //res += n;
    cout << res << "\n";
    return 0;
}