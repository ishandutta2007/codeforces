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

const int maxk = 110;
const int maxn = 200 * 1000;

int64 res[maxk];
int x[maxk];

int a[maxn], b[maxn], c[maxn];

int main()
{
    int tmp, n, k;
    cin >> tmp >> n >> k;
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    for (int i = 0; i < k; ++i)
        scanf("%d", &x[i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
            if (a[i] <= x[j] && x[j] <= b[i])
            {
                res[j] += c[i] + (x[j] - a[i]);
            }
    int64 r = 0;
    for (int i = 0; i < k; ++i)
        r += res[i];
    cout << r << "\n";
    return 0;
}