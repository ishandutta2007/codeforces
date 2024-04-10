#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    int n, f;
    cin >> n >> f;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    vector<int> pr;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(a[i].first, a[i].second);
        if (a[i].first >= a[i].second)
            continue;
        if (2 * a[i].first <= a[i].second)
            pr.push_back(a[i].first);
        else
            pr.push_back(a[i].second - a[i].first);
    }
    sort(pr.rbegin(), pr.rend());
    for (int i = 0; i < min((int)pr.size(), f); i++)
        ans += pr[i];
    cout << ans;
    return 0;
}