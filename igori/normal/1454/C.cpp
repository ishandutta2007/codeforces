#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<vector<int> > pos(n);
        for (int i = 0; i < n; i++) pos[a[i] - 1].push_back(i);
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            if (pos[i].size())
            {
                int cnt = pos[i].size() + 1;
                if (pos[i][0] == 0) cnt--;
                if (pos[i].back() == n - 1) cnt--;
                for (int j = 0; j + 1 < pos[i].size(); j++)
                    if (pos[i][j] + 1 == pos[i][j + 1])
                        cnt--;
                ans = min(ans, max(cnt, 0));
            }
        }
        cout << ans << "\n";
    }
}