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
        string s;
        cin >> s;
        vector<char> a;
        vector<char> b;
        int b1 = 0;
        int b2 = 0;
        int amount1 = 0;
        for(int i = 0; i < n; i++)
        {
            amount1 += (s[i] == '1');
        }
        if(amount1 % 2 != 0)
        {
            cout << "NO\n";
            continue;
        }
        int now1 = 0;
        bool ok = true;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                if(now1 < amount1 / 2)
                {
                    ++b1;
                    ++b2;
                    a.push_back('(');
                    b.push_back('(');
                    ++now1;
                }
                else
                {
                    --b1;
                    --b2;
                    a.push_back(')');
                    b.push_back(')');
                }
            }
            else
            {
                if(b1 > b2)
                {
                    --b1;
                    ++b2;
                    a.push_back(')');
                    b.push_back('(');
                }
                else
                {
                    ++b1;
                    --b2;
                    a.push_back('(');
                    b.push_back(')');
                }
            }
            if(b1 < 0 || b2 < 0)
            {
                cout << "NO\n";
                ok = false;
                break;
            }
        }
        if(!ok)
        {
            continue;
        }
        //cout << b1 << ' ' << b2 << endl;
        if(b1 != 0 || b2 != 0)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++)
        {
            cout << a[i];
        }
        cout << '\n';
        for(int i = 0; i < n; i++)
        {
            cout << b[i];
        }
        cout << '\n';
    }
}