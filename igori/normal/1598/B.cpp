#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<vector<int> > a(n, vector<int>(5));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
                cin >> a[i][j];
        int t = 0;
        for (int i = 0; i < 5 && !t; i++)
        {
            for (int j = i + 1; j < 5 && !t; j++)
            {
                int c1 = 0, c2 = 0, fl = 1;
                for (int st = 0; st < n; st++)
                {
                    c1 += a[st][i];
                    c2 += a[st][j];
                    if (!a[st][i] && !a[st][j])
                        fl = 0;
                }
                if (fl && c1 >= n / 2 && c2 >= n / 2)
                {
                    cout << "YES\n";
                    t = 1;
                }
            }
        }
        if (!t)
            cout << "NO\n";
    }
}