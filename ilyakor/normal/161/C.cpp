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

map<pair<ii, ii>, int> d;

int go(int l1, int r1, int l2, int r2) {
    if (l1 > r1 || l2 > r2) return 0;
    pair<ii, ii> ind(ii(l1, r1), ii(l2, r2));
    if (d.count(ind)) return d[ind];
    int& res = d[ind];
    res = 0;

    int m = max(r1, r2);
    int k = 1;
    while ((1 << k) - 1 <= m) ++k;

    if (k == 1) return res = 1;

    int med = (1 << (k - 1)) - 1;

    bool f1 = l1 <= med && med <= r1;
    bool f2 = l2 <= med && med <= r2;

    if (f1 && f2) res = max(res, min(r1, r2) - max(l1, l2) + 1);

    for (int i = 0; i < 2; ++i) {
        int L1 = l1, R1 = r1;
        if (i == 0) R1 = min(R1, med - 1);
        else {
            L1 = max(L1, med + 1);
            L1 -= med + 1;
            R1 -= med + 1;
        }

        for (int j = 0; j < 2; ++j) {
            int L2 = l2, R2 = r2;
            if (j == 0) R2 = min(R2, med - 1);
            else {
                L2 = max(L2, med + 1);
                L2 -= med + 1;
                R2 -= med + 1;
            }

            res = max(res, go(L1, R1, L2, R2));
        }
    }

    return res;
}

int main()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    --l1, --r1, --l2, --r2;
    cout << go(l1, r1, l2, r2) << "\n";
    return 0;
}