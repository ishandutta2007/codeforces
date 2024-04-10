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

vector<int64> v;

int64 x[3];

bool check(int64 d)
{
    int cur = 0;
    for (int i = 0; i < 3; ++i)
    {
        int l = cur;
        while (cur < sz(v) && v[cur] - v[l] <= d) ++cur;
        x[i] = v[cur - 1] + v[min(l, sz(v) - 1)];
    }
    return cur >= sz(v);
}

int main()
{
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        v[i] = x;
    }
    sort(all(v));
    int64 up = (int64)(2e9) + 100, down = 0;
    while (up - down > 1)
    {
        int64 t = (up + down) / 2;
        if (check(t))
            up = t;
        else
            down = t;
    }
    int64 d = check(down) ? down : up;
    check(d);
    printf("%.6lf\n", ((double)d) * 0.5);
    for (int i = 0; i < 3; ++i)
        printf("%.6lf ", ((double)x[i]) * 0.5);
    printf("\n");
    return 0;
}