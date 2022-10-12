#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;

ll n, m;
ll a[500000];
ll b[500000];
ll cnt[500000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
    }
    int x = a[0];
    int retro = 1;
    for (int i = 1; i < m; i++)
    {
        if (a[i] == x || b[i] == x)
        {
            retro++;
            continue;
        }
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == m - retro)
        {
            cout << "YEs";
            return 0;
        }
        cnt[i] = 0;
    }
    int y = b[0];
    retro = 1;
    for (int i = 1; i < m; i++)
    {
        if (a[i] == y || b[i] == y)
        {
            retro++;
            continue;
        }
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == m - retro)
        {
            cout << "YEs";
            return 0;
        }
    }
    cout << "no";
}