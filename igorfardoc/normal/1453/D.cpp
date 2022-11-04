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
        ll k;
        cin >> k;
        if(k % 2 == 1)
        {
            cout << "-1\n";
            continue;
        }
        vector<int> res;
        ll now = 61;
        while(k > 0)
        {
            while(k >= ((1ll << now) - 2))
            {
                k -= (1ll << now) - 2;
                res.push_back(1);
                for(int i = 0; i < now - 2; i++)
                {
                    res.push_back(0);
                }
            }
            --now;
        }
        cout << res.size() << '\n';
        for(int i = 0; i < res.size(); i++)
        {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
}