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
    int test;
    cin >> test;
    while(test--)
    {
        string t;
        cin >> t;
        int n = t.size();
        vector<int> a(n);
        vector<int> amount(26);
        for(int i = 0; i < n; i++)
        {
            a[i] = (t[i] - 'a');
            ++amount[a[i]];
        }
        vector<int> order;
        vector<bool> there(26, false);
        for(int i = n - 1; i >= 0; i--)
        {
            if(!there[a[i]])
            {
                there[a[i]] = true;
                order.push_back(a[i]);
            }
        }
        reverse(order.begin(), order.end());
        bool ok = true;
        vector<int> amount1(26);
        int len = 0;
        for(int i = 0; i < order.size(); i++)
        {
            if(amount[order[i]] % (i + 1) != 0)
            {
                ok = false;
                break;
            }
            amount1[order[i]] = amount[order[i]] / (i + 1);
            len += amount1[order[i]];
        }
        if(!ok || len > n)
        {
            cout << "-1\n";
            continue;
        }
        vector<int> s;
        for(int i = 0; i < len; i++)
        {
            s.push_back(a[i]);
        }
        int now = len;
        auto snow = s;
        for(int i = 0; i < order.size(); i++)
        {
            vector<int> snow1;
            for(int j = 0; j < snow.size(); j++)
            {
                if(snow[j] != order[i])
                {
                    snow1.push_back(snow[j]);
                }
            }
            snow = snow1;
            for(auto sym : snow1)
            {
                if(now >= n || sym != a[now++])
                {
                    ok = false;
                    break;
                }
            }
            if(!ok)
            {
                break;
            }
        }
        if(!ok || now != n)
        {
            cout << "-1\n";
        }
        else
        {
            for(int i = 0; i < s.size(); i++)
            {
                cout << (char)('a' + s[i]);
            }
            cout << ' ';
            for(int i = 0; i < order.size(); i++)
            {
                cout << (char)('a' + order[i]);
            }
            cout << '\n';
        }
    }   
}