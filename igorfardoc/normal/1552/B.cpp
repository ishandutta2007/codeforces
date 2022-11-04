#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool good(vector<int>& a, vector<int>& b)
{
    int am = 0;
    for(int i = 0; i < 5; i++)
    {
        am += (a[i] < b[i]);
    }
    return am >= 3;
}

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
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(5));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                cin >> a[i][j];
            }
        }
        int now = 0;
        for(int i = 1; i < n; i++)
        {
            if(good(a[i], a[now]))
            {
                now = i;
            }
        }
        bool ok = true;
        for(int i = 0; i < n; i++)
        {
            if(i == now)
            {
                continue;
            }
            if(good(a[i], a[now]))
            {
                cout << "-1\n";
                ok = false;
                break;
            }
        }
        if(ok)
        {
            cout << now + 1 << '\n';
        }
    }
}