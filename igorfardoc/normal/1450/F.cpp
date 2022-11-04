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
        vector<int> a(n);
        vector<int> am(n, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
            am[a[i]]++;
        }
        bool ok = false;
        for(int i = 0; i < n; i++)
        {
            if(am[i] > (n - 1) / 2 + 1)
            {
                cout << -1 << '\n';
                ok = true;
                break;
            }
        }
        if(ok)
        {
            continue;
        }
        int ans = 0;
        vector<int> am1(n, 0);
        am1[a[0]]++;
        am1[a[a.size() - 1]]++;
        int amount = 2;
        for(int i = 1; i < n; i++)
        {
            if(a[i] == a[i - 1])
            {
                am1[a[i - 1]]++;
                am1[a[i]]++;
                amount += 2;
                ++ans;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(am1[i] - 2 > (amount - 2) / 2)
            {
                ans += (am1[i] - 2) - (amount - 2) / 2;
            }
        }
        cout << ans << endl;
    }
}