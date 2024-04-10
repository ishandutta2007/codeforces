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
    int n, k;
    cin >> n >> k;
    --k;
    vi v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(all(v));
    reverse(all(v));
    int cur = 0;
    while (cur < sz(v) && v[cur] >= v[k] && v[cur] > 0) ++cur;
    cout << cur << "\n";
    return 0;
}