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

        vector<int> b;
        vector<int> cnt;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (!b.size() || b.back() != a) b.push_back(a), cnt.push_back(1);
            else cnt[cnt.size() - 1]++;
        }

        int ans = 0;

        for (int i = 0; i < b.size(); i++)
        {
            int x = b[i];
            int res = cnt[i];
            int j = i + 1;
            while (j < b.size())
            {
                res++;
                int L = j, R = b.size();
                while (L + 1 < R)
                {
                    int M = (L + R) / 2;
                    if (b[M] - b[j] >= b[j] - x)
                        R = M;
                    else
                        L = M;
                }
                j = R;
            }
            ans = max(ans, res);
        }

        cout << n - ans << "\n";
    }
}