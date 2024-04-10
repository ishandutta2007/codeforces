#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    struct P{
        int x, y, id;
    };
    vector<P> a(2 * n);
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[2 * i].x = x, a[2 * i].y = y, a[2 * i].id = i;
        a[2 * i + 1].x = y, a[2 * i + 1].y = x, a[2 * i + 1].id = i;
    }
    int idmn = 0;
    sort(a.begin(), a.end(), [&](P a, P b){
         return a.x < b.x;
         });
    for (int i = 0, j = 0; i < 2 * n; i++)
    {
        while (a[j].x < a[i].x)
        {
            if (a[j].y < a[idmn].y)
                idmn = j;
            j++;
        }
        if (a[idmn].y < a[i].y && a[idmn].x < a[i].x)
            ans[a[i].id] = a[idmn].id;
    }
    idmn = 0;
    sort(a.begin(), a.end(), [&](P a, P b){
         return a.y < b.y;
         });
    for (int i = 0, j = 0; i < 2 * n; i++)
    {
        while (a[j].y < a[i].y)
        {
            if (a[j].x < a[idmn].x)
                idmn = j;
            j++;
        }
        if (a[idmn].y < a[i].y && a[idmn].x < a[i].x)
            ans[a[i].id] = a[idmn].id;
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == -1) cout << -1 << " ";
        else cout << ans[i] + 1 << " ";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie((int)false);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}