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
        int right = n - 1;
        int left = -1;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                continue;
            }
            if(i == 0 || s[i - 1] == '0')
            {
                continue;
            }
            right = i - 1;
            break;
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '1')
            {
                continue;
            }
            if(i == n - 1 || s[i + 1] == '1')
            {
                continue;
            }
            left = i;
            break;
        }
        bool ok = true;
        for(int i = right + 1; i <= left; i++)
        {
            if(i == right + 1)
            {
                continue;
            }
            if(s[i] == '0' && s[i - 1] == '1')
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}