#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.push_back(MOD);
    int ans = 1;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (a[j] - a[i] <= 5) j++;
        ans = max(ans, j - i);
    }
    cout << ans << "\n";
}