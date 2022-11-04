#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<vector<int>>> pref(3, vector<vector<int>>(3, vector<int>(n + 1, 0)));
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                pref[i][j][k] = pref[i][j][k - 1] + ((k - 1) % 3 == i && (s[k - 1] - 'a') % 3 == j);
            }
        }
    }
    for(int _ = 0; _ < m; _++)
    {
        int l, r;
        cin >> l >> r;
        --r;
        --l;
        int ans = 0;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i == j)
                {
                    continue;
                }
                int k = 3 - i - j;
                ans = max(ans, pref[0][i][r + 1] - pref[0][i][l] +
                               pref[1][j][r + 1] - pref[1][j][l] + 
                               pref[2][k][r + 1] - pref[2][k][l]);
            }
        }
        cout << r - l + 1 - ans << '\n';
    }
}