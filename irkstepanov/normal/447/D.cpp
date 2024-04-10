/**by Stepanov Ilia**/

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{

    int n, m, k;
    cin >> n >> m >> k;

    ll p;
    cin >> p;

    priority_queue <ll> c, r;

    vector <vector <ll> > a (n, vector <ll> (m));
    for (int i = 0; i < n; i++)
    {
        ll sumc = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            sumc += a[i][j];
        }
        c.push(sumc);
    }

    for (int j = 0; j < m; j++)
    {
        ll sumr = 0;
        for (int i = 0; i < n; i++)
            sumr += a[i][j];
        r.push(sumr);
    }

    vector <ll> sumc(k + 1), sumr(k + 1);
    for (int a = 1; a <= k; a++)
    {
        ll last = c.top();
        c.pop();
        c.push(last - m * p);
        sumc[a] = sumc[a - 1] + last;
    }
    for (int a = 1; a <= k; a++)
    {
        ll last = r.top();
        r.pop();
        r.push(last - n * p);
        sumr[a] = sumr[a - 1] + last;
    }

    ll ans = -200000000000000;
    for (int a = 0; a <= k; a++)
    {
        ll otv = sumc[a] + sumr[k - a];
        otv -= p * a * (k - a);
        ans = max(ans, otv);
    }

    cout << ans;

}