#include <bits/stdc++.h>

using namespace std;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    int n;
    cin >> n;

    int req = 0;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        req += a[i];
    }

    int b[n];
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    pair<int, int> p[n];
    for(int i = 0; i < n; ++i)
        p[i] = make_pair(b[i], a[i]);

    sort(p, p + n);

    int alr = 0;
    int k = 0;
    for(int i = n - 1; i >= 0; --i) {
        alr += p[i].first;
        k++; 

        if(alr >= req)
            break;
    }

    int dp[k + 1][req + 1];

    for(int i = 0; i <= k; ++i) {
        for(int j = 0; j <= req; ++j) {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = k - 1; j >= 0; --j) {
            for(int l = 0; l <= req; ++l) {
                if(dp[j][l] != -1) {
                    dp[j + 1][min(l + b[i], req)] = max(dp[j + 1][min(l + b[i], req)], dp[j][l] + a[i]);
                }
            }
        }
    }

    int t = req - dp[k][req];
    cout << k << " " << t;

    return 0;
}