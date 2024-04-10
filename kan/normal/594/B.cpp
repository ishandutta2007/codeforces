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

const ld pi = acos((ld)-1);

inline ld fr(ld a)
{
    return a - (int)a;
}

int main()
{
    int n, rad, v;
    scanf("%d%d%d", &n, &rad, &v);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int d = b - a;
        ld l = min(0, d - 2 * rad);
        
        ld r = d;
        for (int IT = 0; IT < 70; IT++)
        {
            ld m = (l + r) / 2;
            if (m + 2 * rad * sin(fr(m / 2 / pi / rad) * pi) > d) r = m;
            else l = m;
        }
        
//         cout << m + 2 * sin(fr(m / 2 / pi / rad) * pi) << endl;
        printf("%.20lf\n", (D)(l / v));
    }
    return 0;
}