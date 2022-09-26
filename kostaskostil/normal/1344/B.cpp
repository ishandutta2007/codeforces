#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;
#define int long long

    int n, m;
    vector<string> a;
    int used[1010][1010];

void dfs(int i, int j)
{
    if ((i<0) or (i>=n) or (j<0) or (j>=m))
        return;
    if (a[i][j]=='.') return;
    if (used[i][j]) return;
    used[i][j]=1;

    dfs(i+1, j);
    dfs(i, j+1);
    dfs(i, j-1);
    dfs(i-1, j);
}
bool row()
{
    for (int i=0; i<n; i++)
    {
        bool is=false;
        for (int j=0; j<m; j++)
            if (a[i][j]=='#')
                is=true;
        if (!is)
            return true;
    }
    return false;
}
bool col()
{
    for (int i=0; i<m; i++)
    {
        bool is=false;
        for (int j=0; j<n; j++)
            if (a[j][i]=='#')
                is=true;
        if (!is)
            return true;
    }
    return false;
}
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        a.pb(s);
    }

    for (int i=0; i<n; i++)
    {
        int cnt=(a[i][0]=='#');
        for (int j=0; j<m-1; j++)
            if (a[i][j]=='.')
            if (a[i][j+1]=='#')
                cnt++;
        if (cnt>1)
        {
            cout<<"-1\n";
            return 0;
        }
    }
    for (int i=0; i<m; i++)
    {
        int cnt=(a[0][i]=='#');
        for (int j=0; j<n-1; j++)
            if (a[j][i]=='.')
            if (a[j+1][i]=='#')
                cnt++;
        if (cnt>1)
        {
            cout<<"-1\n";
            return 0;
        }
    }
    if (col() xor row())
    {
        cout<<"-1\n";
        return 0;
    }
    int c=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (used[i][j]==0)
                if (a[i][j]=='#')
                    c++, dfs(i, j);
    cout<<c<<"\n";
    return 0;
}