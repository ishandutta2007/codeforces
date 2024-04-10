#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;

ll n, q;
ll a[500000];
ll go[21][500000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 20; j++)
            go[j][i] = n;
    vector<int> lst(21, n);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (a[i] & (1 << j))
            {
                go[j][i] = i;
            }
        }
        for (int j = 0; j <= 20; j++)
        {
            for (int k = 0; k <= 20; k++)
            {
                if (a[i] & (1 << k))
                    go[j][i] = min(go[j][i], go[j][lst[k]]);
            }
        }
        for (int j = 0; j <= 20; j++)
        {
            if (a[i] & (1 << j))
            {
                lst[j] = i;
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int t = 0;
        for (int j = 0; j <= 20; j++)
        {
            if (go[j][x] <= y && (a[y] & (1 << j)))
                t = 1;
        }
        if (t)
        {
            cout << "Shi\n";
        }
        else
        {
            cout << "Fou\n";
        }
    }
}