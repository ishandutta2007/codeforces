/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5;
int n;

int par[N];
int sal[N];
int a[501][501];
int cnt=0;

void show(vector<int> v)
{
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
}

void make(int root, vector<int>& ver)
{
    //cout<<"Root -> "<<root<<endl;
    //cout<<"Vertexes are : "; show(ver);
    //cout<<endl;

    int mx=0, m=ver.size();
    for(int i=0; i<m; i++)
    {
        int x = ver[i];
        for(int j=0; j<m; j++)
        {
            int y = ver[j];
            mx=max(mx, a[x][y]);
        }
    }
    sal[root]=mx;

    int used[m]={0};
    int i=0;
    while(1)
    {
        while(i<m && used[i]==1) i++;
        if(i==m) break;
        used[i]=1;

        int x = ver[i];

        vector<int> v2;
        v2.push_back(x);

        for(int j=0; j<m; j++)
        {
            if(used[j]==1) continue;
            int y = ver[j];
            if(a[x][y] != mx)
            {
                v2.push_back(y);
                used[j]=1;
            }
        }

        if(v2.size()==1)
        {
            par[v2[0]]=root;
            continue;
        }

        cnt++;
        par[cnt]=root;
        make(cnt, v2);
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }

    for(int i=1;i<=n;i++) sal[i]=a[i][i];

    vector<int> ver;
    for(int i=1;i<=n;i++) ver.push_back(i);

    cnt=n+1;
    make(cnt, ver);

    cout<<cnt<<endl;

    for(int i=1; i<=cnt; i++) cout<<sal[i]<<" ";
    cout<<endl;

    int r = n+1;
    cout<<r<<endl;

    for(int i=1; i<=cnt; i++)
    {
        if(i==r) continue;
        cout<<i<<" "<<par[i]<<endl;
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}