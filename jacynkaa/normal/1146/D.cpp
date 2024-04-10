#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
//#pragma GCC optimize (-O3)
//#define endl tutaj n
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long

int stala = 400000;

vector<int> najmniejszy(stala + 10, -1);
vector<int> dp(stala + 10, 0);
int a, b, m;

void uzupelnij()
{
    priority_queue<pii> Q;
    Q.push(mp(0, 0));
    najmniejszy[0] = 0;
    dp[0] = 1;
    while (!Q.empty())
    {

        int x = Q.top().nd;
        //cerr << x << " " << najmniejszy[x] << endl;
        Q.pop();
        int y = x + a;
        if (y <= min(stala, m) && najmniejszy[y] == -1) //UWAGA
        {
            najmniejszy[y] = max(y, najmniejszy[x]);
            Q.push(mp(-najmniejszy[y], y));
            dp[najmniejszy[y]]++;
        }

        y = x - b;
        if (y >= 0 && najmniejszy[y] == -1)
        {
            najmniejszy[y] = najmniejszy[x];
            Q.push(mp(-najmniejszy[y], y));
            dp[najmniejszy[y]]++;
        }
    }
}

main()
{
    _upgrade;
    cin >> m >> a >> b;
    m = m; // / __gcd(a, b);
    a = a; // / __gcd(a, b);
    b = b; // / __gcd(a, b);
    int gcd = __gcd(a, b);

    if (m > stala)
    {
        while (stala % gcd != (gcd - 1))
            stala--;
    }

    uzupelnij();
    int odp = 1;
    for (int i = 1; i <= min(stala, m); i++)
    {
        dp[i] += dp[i - 1];
        odp += dp[i];
    }
    int l = ((m / gcd) * gcd);
    int x = (stala + 1);
    if (m > stala)
    {
        odp += ((x + l + 2 * gcd) * (((l - x) / gcd) + 1) / 2);
        for (int i = ((m / gcd) * gcd) + gcd - 1; i > m; i--)
            odp -= (i / gcd + 1);
    }
    cout << odp << endl;
}