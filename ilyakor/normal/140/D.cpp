/*
 * Powered by C++Helper v0.001alpha
*/

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

const int L = 710;
const int Z = 350;

int main() {
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(all(v));

    int r1 = 0, r2 = 0;

    int t = 0;
    for (int i = 0; i < sz(v); ++i) {
        t += v[i];
        if (t > L) break;
        ++r1;
        if (t > Z) r2 += t - Z;
    }

    printf("%d %d\n", r1, r2);
    return 0;
}