#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n;
ll a[3000000];
ll b[3000000];
ll cnt = 0;
ll pa[3000000];
ll pb[3000000];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            cin >> a[i];
        else
            cin >> b[i];
        pa[i] = pa[i - 1] + a[i];
        pb[i] = pb[i - 1] + b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ll odd_pref = pb[i - 1];
        ll even_pref = pa[i - 1];
        ll odd_suff = pa[n] - pa[i];
        ll even_suff = pb[n] - pb[i];
        if (odd_pref + odd_suff == even_pref + even_suff)
        {
            //cout << i << endl;
            cnt++;
        }
    }
    cout << cnt;
}