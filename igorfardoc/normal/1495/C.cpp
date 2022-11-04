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
        vector<vector<char> > a(n, vector<char>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        if(m == 1)
        {
            for(int i = 0; i < n; i++)
            {
                a[i][0] = 'X';
            }
        }
        else
        {
            int start = 0;
            if(n % 3 == 0)
            {
                start = 1;
            }
            for(int i = start; i < n; i += 3)
            {
                bool end = false;
                if(n - i <= 2)
                {
                    end = true;
                }
                for(int j = 0; j < m; j++)
                {
                    a[i][j] = 'X';
                }
                if(end)
                {
                    continue;
                }
                if(a[i + 1][1] == 'X' || a[i + 2][1] == 'X')
                {
                    a[i + 1][1] = 'X';
                    a[i + 2][1] = 'X';
                }
                else
                {
                    a[i + 1][0] = 'X';
                    a[i + 2][0] = 'X';
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
}