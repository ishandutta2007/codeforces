#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> k(n);
        for (int i = 0; i < n; i++) cin >> k[i], k[i]--;
        sort(k.rbegin(), k.rend());
        vector<long long> c(m);
        for (int i = 0; i < m; i++) cin >> c[i];
        vector<long long> keep(n);
        for (int i = 0; i < n; i++) keep[i] = c[k[i]];
        for (int i = 1; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 2; i >= 0; i--) keep[i] += keep[i + 1];
        long long ans = 1e18;
        int allow = min(m, n);
        for (int i = 0; i < n; i++)
        {
            allow = min(allow, k[i] + i + 1);
        }
        //cerr << allow << "\n";
        for (int i = 0; i <= allow; i++)
        {
            ans = min(ans, (i ? c[i - 1] : 0) + (i < n ? keep[i] : 0));
        }
        cout << ans << "\n";
    }
}