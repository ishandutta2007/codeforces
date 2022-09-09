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

const ld eps = 1e-11;

const int maxn = 2005;

int a[maxn], b[maxn], c[maxn];
vector<ld> rightangs, leftangs;
int n;
ld ix, iy;

bool isleft(int i, int j)
{
    return a[i] * b[j] - a[j] * b[i] > 0;
}

void intersect(int a1, int b1, int c1, int a2, int b2, int c2)
{
    ld D = a1 * b2 - a2 * b1;
    ld Dx = c1 * b2 - c2 * b1;
    ld Dy = a1 * c2 - a2 * c1;
    ix = Dx / D;
    iy = Dy / D;
}

inline ld getang(ld x1, ld y1, ld x2, ld y2)
{
    return atan2(x1 * y2 - x2 * y1, x1 * x2 + y1 * y2);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        if (c[i] < 0)
        {
            a[i] *= -1;
            b[i] *= -1;
            c[i] *= -1;
        }
    }
    int cnt = 0;
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 0)
        {
            cnt++;
            continue;
        }
        ld dd = sqrt((ld)a[i] * a[i] + (ld)b[i] * b[i]);
        ld d = abs(c[i]) / dd;
        leftangs.clear();
        rightangs.clear();
        for (int j = 0; j < n; j++) if (i != j && c[j] != 0)
        {
            intersect(a[i], b[i], c[i], a[j], b[j], c[j]);
            if (isleft(i, j))
            {
                ld ro = sqrt(ix * ix + iy * iy);
                ld sinphi = -(ix * b[i] - iy * a[i]) / dd / ro;
                ld phi = asin(sinphi);
                ld ang = abs(getang(a[i], b[i], a[j], b[j]));
                leftangs.pb(phi - ang);
//                  cout << phi << ' ' << ang << endl;
            } else
            {
                ld ro = sqrt(ix * ix + iy * iy);
                ld sinphi = -(ix * b[i] - iy * a[i]) / dd / ro;
                ld phi = asin(sinphi);
                ld ang = abs(getang(a[i], b[i], a[j], b[j]));
                rightangs.pb(phi + ang);
//                  cout << "r " << phi << ' ' << ang << endl;
            }
        }
        if (i == 0)
        {
//             cout << leftangs[0] << ' ' << rightangs[0] << endl;
        }
        sort(all(leftangs));
        sort(all(rightangs));
        for (auto t : leftangs)
        {
            answer += upper_bound(all(rightangs), t + eps) - lower_bound(all(rightangs), t - eps);
        }
//          cout << i << ' ' << answer << endl;
    }
    if (cnt == 2) answer += n - 2;
    cout << answer << endl;
    return 0;
}