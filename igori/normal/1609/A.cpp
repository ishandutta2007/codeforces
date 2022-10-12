#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        while (a[i] % 2 == 0) a[i] /= 2, cnt++;
    cout << *max_element(a.begin(), a.end()) * ((1ll << cnt) - 1) + accumulate(a.begin(), a.end(), 0) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}