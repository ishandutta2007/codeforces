#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

char ot(char c)
{
    if(c == '0')
    {
        return '1';
    }
    return '0';
}

bool check(vector<vector<char> > a, vector<int> & rows, vector<int> & cols)
{
    for(int i = 0; i < cols.size(); i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[j][cols[i]] = ot(a[j][cols[i]]);
        }
    }
    for(int i = 0; i < rows.size(); i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[rows[i]][j] = ot(a[rows[i]][j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == '1')
            {
                return false;
            }
        }
    }
    return true;
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
        cin >> n;
        vector<vector<char> > a(n, vector<char>(n));
        vector<vector<char> > b(n, vector<char>(n));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> b[i][j];
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(a[i][j] == b[i][j])
                {
                    a[i][j] = '0';
                }
                else
                {
                    a[i][j] = '1';
                }
            }
        }
        vector<int> cols, rows;
        cols.push_back(0);
        for(int i = 0; i < n; i++)
        {
            if(a[i][0] == '0')
            {
                rows.push_back(i);
            }
        }
        bool there1 = false;
        if(rows.size() > 0 && rows[0] == 0)
        {
            there1 = true;
        }
        for(int i = 1; i < n; i++)
        {
            if((a[0][i] == '0' && there1) || (a[0][i] == '1' && !there1))
            {
                cols.push_back(i);
            }
        }
        if(check(a, rows, cols))
        {
            cout << "YES\n";
            continue;
        }
        cols.clear();
        rows.clear();
        for(int i = 0; i < n; i++)
        {
            if(a[i][0] == '1')
            {
                rows.push_back(i);
            }
        }
        there1 = false;
        if(rows.size() > 0 && rows[0] == 0)
        {
            there1 = true;
        }
        for(int i = 1; i < n; i++)
        {
            if((a[0][i] == '0' && there1) || (a[0][i] == '1' && !there1))
            {
                cols.push_back(i);
            }
        }
        if(check(a, rows, cols))
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}