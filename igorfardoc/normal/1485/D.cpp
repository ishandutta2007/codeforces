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
    vector<vector<int> > a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int b;
            cin >> b;
            if((i + j) % 2 == 0)
            {
                a[i][j] = 720720;
            }
            else
            {
                a[i][j] = b * b * b * b + 720720;
            }
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}