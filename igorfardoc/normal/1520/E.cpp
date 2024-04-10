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
        vector<int> a;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '*')
            {
                a.push_back(i);
            }
        }
        int m = a.size();
        if(m == 0)
        {
            cout << "0\n";
            continue;
        }
        int mid = m / 2;
        int pos = a[mid];
        ll ans = 0;
        for(int i = mid + 1; i < m; i++)
        {
            ans += a[i] - pos - (i - mid);
        }
        for(int i = mid - 1; i >= 0; i--)
        {
            ans += pos - a[i] - (mid - i);
        }
        cout << ans << '\n';
    }
}