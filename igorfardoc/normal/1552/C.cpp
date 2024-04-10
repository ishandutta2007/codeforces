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
        int n, k;
        cin >> n >> k;
        vector<int> to(2 * n, -1);
        for(int i = 0; i < k; i++)
        {
            int v, u;
            cin >> v >> u;
            --v;
            --u;
            to[v] = u;
            to[u] = v;
        }
        vector<int> free;
        for(int i = 0; i < 2 * n; i++)
        {
            if(to[i] == -1)
            {
                free.push_back(i);
            }
        }
        int delta = n - k;
        for(int i = 0; i < (int)free.size() / 2; ++i)
        {
            to[free[i]] = free[i + delta];
            to[free[i + delta]] = free[i];
        }
        int res = 0;
        for(int i = 0; i < 2 * n; i++)
        {
            int v = i;
            int u = to[i];
            if(v > u)
            {
                int k = v;
                v = u;
                u = k;
            }
            for(int j = v + 1; j < u; ++j)
            {
                if(to[j] < v || to[j] > u)
                {
                    ++res;
                }
            }
        }
        cout << res / 4 << '\n';
    }
}