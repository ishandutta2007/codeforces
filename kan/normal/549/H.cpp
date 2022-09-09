#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const ld eps = 1e-10;

int a, b, c, d;

inline pair<ld, ld> getk(ld xl, ld xr, ld yl, ld yr)
{
    if (xl < 0 && xr > 0)
    {
        if (yl < 0 && yr > 0) return {eps, -eps};
        if (yl > 0) return {yl / xr, yl / xl};
        else return {yr / xl, yr / xr};
    }
    return {min(min(yl / xl, yr / xl), min(yl / xr, yr / xr)), max(max(yl / xl, yr / xl), max(yl / xr, yr / xr))};
}

inline bool can(ld m)
{
    auto t1 = getk(a - m, a + m, c - m, c + m);
    auto t2 = getk(b - m, b + m, d - m, d + m);
//     cout << "can " << (double)m << endl;
//     cout << (double)t1.first << ' ' << (double)t1.second << endl;
//     cout << (double)t2.first << ' ' << (double)t2.second << endl;
    if (t1.first > t1.second)
    {
        if (t2.first > t2.second) return true;
        if (t2.first > t1.second && t2.second < t1.first) return false;
        return true;
    }
    if (t2.first > t2.second)
    {
        if (t1.first > t2.second && t1.second < t2.first) return false;
        return true;
    }
    return min(t1.second, t2.second) > max(t1.first, t2.first);
}

int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ld l = 0;
    ld r = 1e9;
    for (int IT = 0; IT < 100; IT++)
    {
        ld m = (l + r) / 2;
        if (can(m)) r = m;
        else l = m;
    }
    cout.precision(20);
    cout << r << endl;
	return 0;
}