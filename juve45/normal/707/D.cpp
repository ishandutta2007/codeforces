#include <bits/stdc++.h>
#define inf 100000012
#define DMAX 100009
#define NMAX 1009
using namespace std;

vector <pair<int, vector <int> > > v[DMAX];

int n, m, x, a, b, q;
int curr_nr;

int inv[NMAX];
int mat[NMAX][NMAX];
int cnt[NMAX];
int ans[DMAX];

int solve(vector <int> v)
{

    if(v[0]==1)
    {
        int i=v[1];
        int j=v[2];
        if(inv[i]+mat[i][j]!=1)
        {
            mat[i][j]=1-mat[i][j];
            cnt[i]++;
            curr_nr++;
            return 1;
        }
        return 0;
    }
    if(v[0]==2)
    {
        int i=v[1];
        int j=v[2];
        if(inv[i]+mat[i][j]==1)
        {
            mat[i][j]=1-mat[i][j];
            cnt[i]--;
            curr_nr--;
            return 1;
        }
        return 0;
    }
    if(v[0]==3)
    {
        int i=v[1];
        inv[i]=1-inv[i];
        curr_nr+=m-2*cnt[i];
        cnt[i]=m-cnt[i];
        return 1;
    }
    if(v[0]==4)
        return 0;
}

void unsolve(vector <int> v)
{
    if(v[0]==2)
    {
        int i=v[1];
        int j=v[2];
            mat[i][j]=1-mat[i][j];
            cnt[i]++;
            curr_nr++;

    }
    if(v[0]==1)
    {
        int i=v[1];
        int j=v[2];
       mat[i][j]=1-mat[i][j];
            cnt[i]--;
            curr_nr--;
    }

    if(v[0]==3)
    {
        int i=v[1];
        curr_nr+=m-2*cnt[i];
        cnt[i]=m-cnt[i];
        inv[i]=1-inv[i];
    }
}

void dfs(int nod)
{
int ch;
ans[nod]=curr_nr;
    for(int i=0;i<v[nod].size();i++)
    {
        vector <int> vt=v[nod][i].second;
        ch=solve(vt);
        dfs(v[nod][i].first);
        if(ch)
            unsolve(vt);
    }
}

int main()
{

    cin>>n>>m>>q;
    int current_state=0;
    for(int i=1;i<=q;i++)
    {
        cin>>x;
        if(x==4)
        {
            cin>>a;
            vector <int> op;
            op.push_back(x);
            v[a].push_back({i, op});
        }
        else if(x==1 || x==2)
        {
            cin>>a>>b;
            vector <int> op;
            op.push_back(x);
            op.push_back(a);
            op.push_back(b);
            v[current_state].push_back({i, op});

        }
        else if(x==3)
        {
            cin>>a;
            vector <int> op;
            op.push_back(x);
            op.push_back(a);
            v[current_state].push_back({i, op});

        }
        current_state=i;
    }

    dfs(0);

    for(int i=1;i<=q;i++)
        cout<<ans[i]<<'\n';
    return 0;
}