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
        bool ok = false;
        for(int i = 0; i < n; i++)
        {
            vector<int> am(2);
            for(int j = i; j < n; j++)
            {
                am[s[j] - 'a']++;
                if(am[0] == am[1])
                {
                    ok = true;
                    cout << i + 1 << ' ' << j + 1 << '\n';
                    break;
                }
            }
            if(ok)
            {
                break;
            }
        }
        if(!ok)
        {
            cout << "-1 -1\n";
        }
    }
}