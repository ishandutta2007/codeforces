#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define pb push_back
#define mp make_pair

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int maxn = 200005;

int a[maxn], orr[maxn];
int n, k, x;

int main()
{
    scanf("%d%d%d", &n, &k, &x);
    ll powx = 1;
    for (int i = 0; i < k; i++) powx *= x;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) orr[i + 1] = orr[i] | a[i];
    int curor = 0;
    ll answer = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        answer = max(answer, (ll)curor | (ll)orr[i] | (a[i] * powx));
        curor |= a[i];
    }
    cout << answer << endl;
    return 0;
}