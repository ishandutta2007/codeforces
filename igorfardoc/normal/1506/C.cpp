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
        string a, b;
        cin >> a >> b;
        int n = a.length();
        int m = b.length();
        set<string> s;
        s.insert("");
        for(int i = 0; i < n; i++)
        {
            string now = "";
            for(int j = i; j < n; j++)
            {
                now += a[j];
                s.insert(now);
            }
        }
        int ans = n + m;
        for(int i = 0; i < m; i++)
        {
            string now = "";
            for(int j = i; j < m; j++)
            {
                now += b[j];
                if(s.find(now) != s.end())
                {
                    ans = min(ans, n + m - 2 * (j - i + 1));
                }
            }
        }
        cout << ans << '\n';
    }
}