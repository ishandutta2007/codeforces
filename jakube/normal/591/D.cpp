#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define lld long long
#define llu unsigned long long
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const lld MOD = 1000000007ll;

template<typename T>
T read()
{
    T tmp;
    cin >> tmp;
    return tmp;
}
#define readi read<int>
#define readl read<lld>

template<typename T>
vector<T> reads(int count)
{
    vector<T> values;
    values.reserve(count);
    for (int i = 0; i < count; i++)
        values.push_back(read<T>());
    return values;
}
#define readsi reads<int>
#define readsl reads<lld>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    double x1, y1, x2, y2, v, t, vx, vy, wx, wy;
    cin >> x1 >> y1 >> x2 >> y2 >> v >> t >> vx >> vy >> wx >> wy;

    //binary search
    double L = 0;
    double R = 1e9;
    double M;

    while (R-L> 1e-7)
    {
          M = (L+R)/2;
          double x = x1 + min(t, M) * vx + max(0., M-t) * wx;
          double y = y1 + min(t, M) * vy + max(0., M-t) * wy;

        //distance left to goal
          x -= x2;
          y -= y2;

        if (hypot(x, y) <= M*v)
            R = M;
        else
            L = M;
    }
    cout << R << '\n';
}