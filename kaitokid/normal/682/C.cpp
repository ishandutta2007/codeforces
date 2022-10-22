#include <bits/stdc++.h>

using namespace std;
long a[100020];
vector <pair<int,int> > v [100002];

int f(int parent,int x){


if(x!=1&&v[x].size()==1)return 1;
else{
    int s =0;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i].first!=parent){s+=f(x,v[x][i].first);}
    }
 return s+1;


}
    }


int ans=0;
int dfs(int x,int parent,int l)
{if(l<0){l=0;}

    if(a[x]<l){ ans+=f(parent,x);return 0;}
   else{ for(int i=0;i<v[x].size();i++)
    {if(v[x][i].first!=parent)
        dfs(v[x][i].first,x,l+v[x][i].second);
    }

}}
int main()
{
    int n,x,y,z;
    cin>>n;
    for(int i=1;i<=n;i++)
    {cin>>a[i];

    }
    for(int i=2;i<=n;i++)
    {
        cin>>x>>z;
        v[x].push_back(make_pair(i,z));
        v[i].push_back(make_pair(x,z));
    }
    dfs(1,-1,0);
    cout<<ans;
int u;
    //cin>>u;
    //cout<<f(7,3);
    return 0;
}