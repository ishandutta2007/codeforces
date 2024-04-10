#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v[200009];
vector<int>r[2];
bool bl[25];
int n,ans[200009];
void go(int x,int p,int u)
{
    r[u].push_back(x);
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=p)go(v[x][i],x,1-u);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)v[i].clear();
        r[0].clear();
        r[1].clear();
        for(int i=0;i<22;i++)bl[i]=0;
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);

        }
       go(1,0,0);
       if(r[0].size()>r[1].size())swap(r[0],r[1]);
       int u=r[0].size();
       for(int i=0;i<22;i++)
            if(u&(1<<i))bl[i]=true;
       int lg=-1;
       int id0=0,id1=0;
       for(int i=1;i<=n;i++)
       {
           if((i&(i-1))==0)lg++;
           if(bl[lg])ans[r[0][id0++]]=i;
           else ans[r[1][id1++]]=i;
       }
      for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
      cout<<endl;
    }
    return 0;
}