#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



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
        vector<ll> d(2 * n);
        for(int i = 0; i < 2 * n; i++)
        {
            cin >> d[i];
        }
        sort(d.begin(), d.end());
        bool ok = true;
        vector<ll> a;
        for(int i = 0; i < n; i++)
        {
            a.push_back(d[i * 2]);
            if(d[i * 2 + 1] != d[i * 2])
            {
                ok = false;
                break;
            }
            if(i != n && d[i * 2 + 1] == d[i * 2 + 2])
            {
                ok = false;
                break;
            }
        }
        if(!ok)
        {
            cout << "NO\n";
            continue;
        }
        vector<ll> ans;
        ans.push_back(0);
        for(int i = 0; i < n - 1; i++)
        {
            ll delta = a[i + 1] - a[i];
            if(delta % (2 * i + 2) != 0)
            {
                ok = false;
                break;
            }
            ans.push_back(ans[ans.size() - 1] + delta / ((2 * i + 2)));
        }
        if(!ok)
        {
            cout << "NO\n";
            continue;
        }
        ll sum = 0;
        for(int i = 0; i < n - 1; i++)
        {
            sum += (ans[n - i - 1] - ans[n - i - 2]) * (i + 1);
        }
        if(sum * 2 >= a[0] || (a[0] - sum * 2) % n != 0)
        {
            ok = false;
        }
        if(!ok)
        {
            cout << "NO\n";
            continue;
        }
        if(((a[0] - sum * 2) / n) % 2 != 0)
        {
            ok = false;
        }
        if(!ok)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}