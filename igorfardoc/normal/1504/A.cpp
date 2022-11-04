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
        string s;
        cin >> s;
        int n = s.length();
        bool ok = true;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != 'a')
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            cout << "NO\n";
            continue;
        }
        int start = 0;
        int end = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a')
            {
                ++start;
            }
            else
            {
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == 'a')
            {
                ++end;
            }
            else
            {
                break;
            }
        }
        cout << "YES\n";
        if(start >= end)
        {
            cout << 'a' << s << '\n';
        }
        else
        {
            cout << s << 'a' << '\n';
        }
    }
}