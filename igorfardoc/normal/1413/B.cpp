#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > rows(n, vector<int>(m));
        vector<vector<int> > cols(m, vector<int>(n));
        vector<int> eltocol(n * m + 1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> rows[i][j];
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> cols[i][j];
                eltocol[cols[i][j]] = j;
            }
        }
        vector<vector<int> > mass(n, vector<int>(m));
        for(int i = 0; i < n; i++)
        {
            mass[eltocol[rows[i][0]]] = rows[i];
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout << mass[i][j] << " ";
            }
            cout << "\n";
        }
    }
}