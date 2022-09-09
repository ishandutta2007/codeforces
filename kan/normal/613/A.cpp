#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second

const ld pi= acos((ld)-1.0);

struct pt
{
    int x, y;
    
    inline ld len() const
    {
        return sqrt((ld)x * x + (ld)y * y);
    }
};

inline pt operator-(const pt &a, const pt &b)
{
    return {a.x - b.x, a.y - b.y};
}

inline ll operator/(const pt &a, const pt &b)
{
    return (ll)a.x * b.x + (ll)a.y * b.y;
}

inline ll operator*(const pt &a, const pt &b)
{
    return (ll)a.x * b.y - (ll)a.y * b.x;
}

pt p[100005];

int main()
{
    int n, px, py;
    scanf("%d", &n);
    scanf("%d%d", &px, &py);
    ld mind = 1e18;
    ld maxd = 0;
    for (int i = 0; i < n; i++)
    {
        int ax, ay;
        scanf("%d%d", &ax, &ay);
        ld d = sqrt(((ld)ax - px) * (ax - px) + ((ld)ay - py) * (ay - py));
        mind = min(mind, d);
        maxd = max(maxd, d);
        p[i] = {ax, ay};
    }
    p[n] = p[0];
    pt P = {px, py};
    for (int i = 0; i < n; i++)
    {
        if ((P - p[i]) / (p[i + 1] - p[i]) > 0 && (P - p[i + 1]) / (p[i] - p[i + 1]) > 0)
        {
            ld d = (P - p[i]) * (p[i + 1] - p[i]) / (p[i + 1] - p[i]).len();
            mind = min(mind, abs(d));
        }
    }
    cout.precision(20);
    cout << (D)(pi * (maxd * maxd - mind * mind)) << endl;
    return 0;
}