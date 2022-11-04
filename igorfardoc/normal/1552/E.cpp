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
    int n, k;
    cin >> n >> k;
    vector<int> a(n * k);
    vector<vector<int> > b(n);
    for(int i = 0; i < n * k; i++)
    {
        cin >> a[i];
        b[a[i] - 1].push_back(i);
    }
    vector<pair<int, int>> ans(n);
    int amount = (n - 1) / (k - 1) + 1;
    vector<int> left(n);
    for(int i = 0; i < n; i++)
    {
        left[i] = i;
    }
    for(int _ = 0; _ < (n - 1) / amount + 1; _++)
    {
        vector<pair<int, int>> c;
        for(int i = 0; i < left.size(); i++)
        {
            c.push_back({b[left[i]][_ + 1], left[i]});
        }
        sort(c.begin(), c.end());
        left.clear();
        for(int i = 0; i < min((int)c.size(), amount); ++i)
        {
            ans[c[i].second] = {b[c[i].second][_], b[c[i].second][_ + 1]};
        }
        for(int i = amount; i < c.size(); i++)
        {
            left.push_back(c[i].second);
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
}