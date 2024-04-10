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
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<ll> pref0(n, 0);
        vector<ll> pref1(n, 0);
        pref0[0] = a[0];
        for(int i = 1; i < n; i++)
        {
            pref0[i] = pref0[i - 1];
            pref1[i] = pref1[i - 1];
            if(i % 2 == 1)
            {
                pref1[i] += a[i];
            }
            else
            {
                pref0[i] += a[i];
            }
        }
        vector<ll> sums(n, 0);
        bool there = false;
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 1)
            {
                sums[i] = pref1[i] - pref0[i];
            }
            else
            {
                sums[i] = pref0[i] - pref1[i];
            }
            if(sums[i] < 0)
            {
                there = true;
            }
            //cout << sums[i] << ' ';
        }
        //cout << endl;
        if(!there && sums[n - 1] == 0)
        {
            cout << "YES\n";
            continue;
        }
        if(abs(sums[n - 1]) % 2 != 0)
        {
            cout << "NO\n";
            continue;
        }
        ll need = sums[n - 1] / 2;
        bool ok = false;
        vector<ll> suff0(n), suff1(n);
        if((n - 1) % 2 == 0)
        {
            suff0[n - 1] = sums[n - 1];
            suff1[n - 1] = 1000000000000000000ll;
        }
        else
        {
            suff1[n - 1] = sums[n - 1];
            suff0[n - 1] = 1000000000000000000ll; 
        }
        for(int i = n - 2; i >= 0; i--)
        {
            suff1[i] = suff1[i + 1];
            suff0[i] = suff0[i + 1];
            if(i % 2 == 0)
            {
                suff0[i] = min(suff0[i], sums[i]);
            }
            else
            {
                suff1[i] = min(suff1[i], sums[i]);
            }
        }
        for(int i = 0; i < n - 1; i++)
        {
            //cout << i;
            if(i != 0 && sums[i - 1] < 0)
            {
                break;
            }
            ll delta = a[i + 1] - a[i];
            if(i != n - 2)
            {
                if(abs(delta) != abs(need))
                {
                    continue;
                }
                if(i % 2 == (n - 1) % 2 && ((delta > 0 && sums[n - 1] > 0) || (delta < 0 && sums[n - 1] < 0)))
                {
                    continue;
                }
                if(i % 2 != (n - 1) % 2 && ((delta < 0 && sums[n - 1] > 0) || (delta > 0 && sums[n - 1] < 0)))
                {
                    continue;
                }
            }
            else
            {
                if(sums[i + 1] - 2 * delta != 0)
                {
                    continue;
                }
            }
            if(sums[i] + delta < 0)
            {
                continue;
            }
            if(sums[i + 1] - 2 * delta < 0)
            {
                continue;
            }
            if(i == n - 2)
            {
                cout << "YES\n";
                ok = true;
                break;
            }
            if(i % 2 == 0)
            {
                if(suff0[i + 2] + 2 * delta >= 0 && suff1[i + 2] - 2 * delta >= 0)
                {
                    cout << "YES\n";
                    ok = true;
                    break;
                }
            }
            if(i % 2 == 1)
            {
                if(suff1[i + 2] + 2 * delta >= 0 && suff0[i + 2] - 2 * delta >= 0)
                {
                    cout << "YES\n";
                    ok = true;
                    break;
                }
            }
        }
        if(!ok)
        {
            cout << "NO\n";
        }
    }
}