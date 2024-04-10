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

const int maxn = 200 * 1000;

int a[maxn];
int rev[maxn];
int d[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    rev[n] = 0;
    int sum = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        sum += a[i];
        rev[i] = max(rev[i + 1] + a[i], -sum);
    }
    int res = 0;
    sum = 0;
    d[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i - 1];
        d[i] = max(d[i - 1] + a[i - 1], -sum);
    }
    for (int i = 0; i <= n; ++i)
    {
        res = max(res, d[i] + rev[i]);
    }
    cout << res << "\n";
    return 0;
}