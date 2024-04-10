#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int> > a(n, vector<int>(5));
        int id = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
                cin >> a[i][j];
            int cnt = 0;
            for (int j = 0; j < 5; j++)
                if (a[i][j] < a[id][j])
                    cnt++;
            if (cnt >= 3)
                id = i;
        }
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < 5; j++)
                if (a[i][j] < a[id][j])
                    cnt++;
            if (cnt >= 3 && i != id)
            {
                id = -2;
                break;
            }
        }
        cout << id + 1 << "\n";
    }
}