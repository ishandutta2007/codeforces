#include <bits/stdc++.h>

#define mp std::make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

int max(int a, int b)
{
    return (a > b ? a : b);
}

int min(int a, int b)
{
    return (a < b ? a : b);
}

typedef long long ll;

int main()
{

    int n;
    ll k;
    scanf("%d %I64d\n", &n, &k);

    std::vector <ll> m(n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &m[i]);

    std::map <ll, ll> L;
    std::vector <ll> l(n);

    for (int i = 0; i < n; i++)
    {
        if (m[i] % k == 0)
        {
            if (L.count(m[i] / k))
                l[i] = L[m[i] / k];
        }
        ++L[m[i]];
    }

    std::map <ll, ll> R;
    std::vector <ll> r(n);

    for (int i = n - 1; i >= 0; i--)
    {
        if (R.count(m[i] * k))
            r[i] = R[m[i] * k];
        ++R[m[i]];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += l[i] * r[i];

    printf("%I64d\n", ans);

}