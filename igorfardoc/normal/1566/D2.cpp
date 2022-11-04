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
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n * m);
        vector<pair<int, int>> b(n * m);
        vector<int> pos(n * m);
        for(int i = 0; i < n * m; i++)
        {
            cin >> a[i];
            b[i] = {a[i], i};
        }
        sort(b.begin(), b.end());
        for(int i = 0; i < n * m; i++)
        {
            pos[b[i].second] = i;
        }
        vector<vector<int>> mass(n, vector<int>(m, -1));
        ll res = 0;
        for(int i = 0; i < n * m; i++)
        {
            int row = pos[i] / m;
            int col = pos[i] % m;
            for(int j = 0; j < col; j++)
            {
                if(mass[row][j] != -1 && mass[row][j] != a[i])
                {
                    ++res;
                }
            }
            mass[row][col] = a[i];
        }
        cout << res << '\n';
    }
}