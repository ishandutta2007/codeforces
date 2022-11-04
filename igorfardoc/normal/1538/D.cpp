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
    vector<int> pr;
    vector<bool> ok(100000, false);
    for(int i = 2; i < 100000; i++)
    {
        if(!ok[i])
        {
            pr.push_back(i);
            for(ll j = (ll)i * i; j < 100000; j += i)
            {
                ok[j] = true;
            }
        }
    }
    while(t--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        if(a == b && k == 1)
        {
            cout << "NO\n";
            continue;
        }
        if(k == 1)
        {
            if(max(a, b) % min(a, b) != 0)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
            continue;
        }
        int am = 0;
        for(int i = 0; i < pr.size() && (ll)pr[i] * pr[i] <= a; i++)
        {
            while(a % pr[i] == 0)
            {
                a /= pr[i];
                ++am;
            }
        }
        if(a > 1)
        {
            ++am;
        }
        for(int i = 0; i < pr.size() && (ll)pr[i] * pr[i] <= b; i++)
        {
            while(b % pr[i] == 0)
            {
                b /= pr[i];
                ++am;
            }
        }
        if(b > 1)
        {
            ++am;
        }
        if(k <= am)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}