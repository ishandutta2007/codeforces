#include <iostream>
#include <vector>
#include <cstdio>
#define DMAX 100002
using namespace std;

vector <int> v[DMAX], cc;

int lv[3], c=0, a[DMAX], b[DMAX], n;
bool use[DMAX];

void dfs(int node, int level)
{
    int ok=0;
    use[node]=1;
    int l;
    if(level%2==0)
        l=2;
    else l=1;

    if(a[node]!=(b[node]^lv[l]))
    {
        lv[l]=1-lv[l];
        c++;
        ok=1;
        cc.push_back(node);
    }
    for(int i=0; i<v[node].size(); i++)
    {
        if(!use[v[node][i]])
        dfs(v[node][i], level+1);
    }
    if(ok==1)
        lv[l]=1-lv[l];
}

int main()
{
    //freopen("ala.txt", "r", stdin);

    int f,g;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        cin>>f>>g;
        v[f].push_back(g);
        v[g].push_back(f);
    }
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
        cin>>b[i];

    dfs(1, 1);
    cout<<c<<'\n';
    for(int i=0;i<c;i++)
        cout<<cc[i]<<' ';
    return 0;
}