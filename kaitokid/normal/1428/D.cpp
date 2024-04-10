#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,res;
int p[100009];
stack<pair<int,int> > st[5];
//stack<pair<int,int> >c[2];
vector<int>f[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>p[i];
    for(int i=1;i<=n;i++)st[0].push({i,0});
    for(int i=n;i>0;i--)
    {
        if(p[i]==0)
        {
            if(st[0].empty()){cout<<-1;return 0;}
        continue;
        }
        if(p[i]==1)
        {
            if(st[0].empty()){cout<<-1;return 0;}
            int u=st[0].top().first;
            st[0].pop();
            f[u].push_back(i);
            res++;
            st[1].push({u,i});
            continue;
        }
        if(p[i]==2)
        {
            if(st[1].empty()){cout<<-1;return 0;}
            int u=st[1].top().first;
            st[1].pop();
            f[u].push_back(i);
            res++;
            st[2].push({u,i});
            continue;
        }
       if(st[0].empty()){cout<<-1;return 0;}
int u=st[0].top().first;
st[0].pop();
if(!st[2].empty())
{
    int v=st[2].top().first;
    int z=st[2].top().second;
    st[2].pop();
    f[u].push_back(i);
    f[u].push_back(z);
    st[2].push({u,i});
    res+=2;

continue;
}
if(!st[1].empty())
{
      int v=st[1].top().first;
    int z=st[1].top().second;
    st[1].pop();
    f[u].push_back(i);
    f[u].push_back(z);
    st[2].push({u,i});
    res+=2;



continue;}

cout<<-1;
return 0;
    }
    cout<<res<<endl;
    for(int i=1;i<=n;i++)
        for(int j=0;j<f[i].size();j++)
        cout<<i<<" "<<f[i][j]<<endl;
    return 0;
}