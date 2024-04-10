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

const int maxn = 100005;
const ld eps = 1e-7;

double A[maxn], B[maxn];
ld a1[maxn], a2[maxn];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &B[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &A[i]);
    }
    ld v1 = 0;
    ld v2 = 0;
    for (int i = 0; i < n; i++)
    {
        ld C = A[i] + B[i];
        ld AA = -1;
        ld BB = -v2 + v1 + C;
        ld CC = C * v2 - B[i];
        ld DD = BB * BB - 4 * AA * CC;
//         cout << i << ' ' << DD << endl;
        assert(DD > -eps);
        DD = abs(DD);
        a2[i] = (-BB + sqrt(DD)) / 2 / AA;
        a1[i] = C - a2[i];
//         cout << "set " << a1[i] << ' ' << a2[i] << endl;
        v1 += a1[i];
        v2 += a2[i];
    }
    for (int i = 0; i < n; i++) printf("%.7lf ", abs((double)a1[i]));
    printf("\n");
    for (int i = 0; i < n; i++) printf("%.7lf ", abs((double)a2[i]));
    printf("\n");
    return 0;
}