#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    sort(all(a));
    vector<int> ans(n);
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (pos > a[i].second)
        {
            ans[a[i].second] = pos - a[i].second;
        }
        else
        {
            pos = a[i].second;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] - 1 << " ";
}