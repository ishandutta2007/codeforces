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

const int maxn = 2005;
const int MAX = 5005;

ll k[MAX];
int cnt[MAX];
int a[maxn];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++) cnt[a[i] - a[j]]++;
    }
    int suma = 0;
    for (int i = 0; i < MAX; i++)
    {
        suma = cnt[i];
        int sumb = 0;
        for (int j = 0; i + j < MAX; j++)
        {
            sumb = cnt[j];
            k[i + j] += (ll)suma * sumb;
//             cout << i << ' ' << j << ' ' << suma * sumb << endl;
        }
    }
    suma = 0;
    ld answer = 0;
    for (int i = MAX - 1; i > 0; i--)
    {
        answer += (ld)suma * k[i];
        suma += cnt[i];
    }
    ld all = suma;
    all *= (all * all);
    cout.precision(20);
//     cout << (D)answer << ' ' << (D)all << endl;
    cout << (D)(answer / all) << endl;
    return 0;
}