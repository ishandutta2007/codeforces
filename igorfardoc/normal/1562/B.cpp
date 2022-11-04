#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int a)
{
    if(a == 1)
    {
        return true;
    }
    for(int i = 2; i * i <= a; i++)
    {
        if(a % i == 0)
        {
            return true;
        }
    }
    return false;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<char> a(n);
        char good = '#';
        vector<int> b(10);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[a[i] - '0']++;
            if(a[i] == '1' || a[i] == '9' || ((a[i] - '0') % 2 == 0 && a[i] != '2'))
            {
                good = a[i];
            }
        }
        if(good != '#')
        {
            cout << "1\n";
            cout << good << '\n';
            continue;
        }
        bool ok = false;
        for(int i = 0; i < 10; i++)
        {
            if(b[i] > 1)
            {
                cout << "2\n";
                cout << i << i << '\n';
                ok = true;
                break;
            }
        }
        if(ok)
        {
            continue;
        }
        int ans = -1;
        int minamount = 10000;
        for(int i = 0; i < (1 << n); i++)
        {
            int now = 0;
            int now1 = 1;
            int amount = 0;
            for(int j = 0; j < n; j++)
            {
                if((i >> j) & 1)
                {
                    now += now1 * (a[n - j - 1] - '0');
                    ++amount;
                    now1 *= 10;
                }
            }
            if(check(now) && amount < minamount)
            {
                minamount = amount;
                ans = now;
            }
        }
        cout << minamount << '\n';
        cout << ans << '\n';
    }
}