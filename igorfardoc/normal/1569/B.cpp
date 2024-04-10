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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<vector<char>> ans(n, vector<char>(n));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                {
                    ans[i][i] = 'X';
                }
                else
                {
                    ans[i][j] = '=';
                }
            }
        }
        vector<int> a;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '2')
            {
                a.push_back(i);
            }
        }
        if(a.size() == 1 || a.size() == 2)
        {
            cout << "NO\n";
            continue;
        }
        for(int i = 0; i < a.size(); i++)
        {
            ans[a[i]][a[(i + 1) % a.size()]] = '+';
            ans[a[(i + 1) % a.size()]][a[i]] = '-';
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
}