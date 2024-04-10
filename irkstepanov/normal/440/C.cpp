#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const ll inf = 200000000000000;

ll m[17];

int solve (ll n, int d)
{
    //cout << n << " " << d << "\n";
    if (!n) return 0;
    if (n == 1) return 1;
    int ans = 0;
    while (n >= m[d])
    {
        n -= m[d];
        ans += d;
    }
    int k1 = ans + solve (n, d - 1);
    int k2 = ans + d + solve (abs(n - m[d]), d - 1);
    return min(k1, k2);
}

int main()
{

    m[1] = 1;
    for (int i = 2; i <= 16; i++)
        m[i] = m[i - 1] * 10 + 1;

    ll n;
    cin >> n;

    cout << solve (n, 16);

}