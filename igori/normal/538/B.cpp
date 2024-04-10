#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

long long n, k;
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector<int> d;
    for (int i = 0; i < s.size(); i++)
        d.push_back(s[i] - '0');
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
        ans = max(ans, d[i]);
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
    {
        int x = 0;
        for (int j = 0; j < d.size(); j++)
        {
            x = 10 * x;
            if (d[j] > 0)
            {
                d[j]--;
                x++;
            }
        }
        cout << x << " ";
    }
}