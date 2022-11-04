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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> c[i] >> d[i];
    }
    vector<int> pref(1000001, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i] > c[j])
            {
                continue;
            }
            pref[c[j] - a[i]] = max(pref[c[j] - a[i]], d[j] - b[i] + 1);
        }
    }
    int ans = 1000001;
    int max1 = 0;
    for(int i = 1000000; i >= 0; i--)
    {
        max1 = max(max1, pref[i]);
        ans = min(ans, i + max1);
    }
    cout << ans;
}