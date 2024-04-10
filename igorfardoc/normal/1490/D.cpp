#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> res;
vector<int> a;

void solve(int l, int r, int d)
{
    if(l > r)
    {
        return;
    }
    int id1 = -1;
    int max1 = -1;
    for(int i = l; i <= r; i++)
    {
        if(max1 < a[i])
        {
            max1 = a[i];
            id1 = i;
        }
    }
    res[id1] = d;
    solve(l, id1 - 1, d + 1);
    solve(id1 + 1, r, d + 1);
}


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
        a.resize(n);
        res.resize(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(0, n - 1, 0);
        for(int i = 0; i < n; i++)
        {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
}