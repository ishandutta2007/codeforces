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
        vector<bool> was(26, false);
        bool ok = true;
        for(int i = 0; i < n; i++)
        {
            if(was[s[i] - 'A'])
            {
                if(s[i - 1] == s[i])
                {
                    continue;
                }
                else
                {
                    cout << "NO\n";
                    ok = false;
                    break;
                }
            }
            else
            {
                was[s[i] - 'A'] = true;
            }
        }
        if(ok)
        {
            cout << "YES\n";
        }
    }
}