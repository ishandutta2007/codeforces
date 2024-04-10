#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>g[100009];
bool ff[100009];
int lst[100009];
int a[100009];
void go(int x)
{
    for(int i=0;i<g[x].size();i++)if(g[x][i]!=lst[x])cout<<g[x][i]<<" ";
    if(lst[x]!=-1)cout<<lst[x]<<" ";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k=0;
        cin>>n;
        for(int i=0;i<=n+1;i++)
        {
            g[i].clear();
            ff[i]=false;
            lst[i]=-1;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]<i)k=max(k,a[i]);
            if(a[i]>i)k=max(k,i);
            ff[a[i]]=1;
            g[a[i]].push_back(i);
        }
        int h=-1;
        for(int i=0;i<=n+1;i++)
        {
            if(g[i].empty())continue;
            for(int j=0;j<g[i].size();j++)if(ff[g[i][j]])lst[i]=g[i][j];
            if(lst[i]==-1)h=i;
        }
        vector<int>cmp;
        while(true)
        {
            cmp.push_back(h);
            if(h==0||h==n+1)break;
            h=a[h];
        }
        reverse(cmp.begin(),cmp.end());
        cout<<k<<endl;
        for(int i=0;i<cmp.size();i++)go(cmp[i]);
        cout<<endl;

    }
    return 0;
}