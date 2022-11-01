#include <iostream>
#include<vector>

using namespace std;

typedef pair<int,int>pii;
vector<int>G[1001000],l;
int best[1001000],e,s,ans,an;
int n,m,k;

void bfs()
{
    int p=0;
    while(p<l.size())
    {
        for(int i=0;i<G[l[p]].size();i++)
        {
            int v=G[l[p]][i];
            if(best[v]>best[l[p]]+1)
            {
                l.push_back(v);
                best[v]=best[l[p]]+1;
            }
        }
        p++;
    }
}
int main()
{

    char c[1010][1010];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            k=i*m+j;
            cin>>c[i][j];
            if(c[i][j]!='T')
            {
                best[k]=1;
                if(c[i][j]=='E')
                    e=k;
                if(c[i][j]=='S')
                    s=k;
                if(i>0)
                    if(best[k-m]==1)
                    {
                        G[k].push_back(k-m);
                        G[k-m].push_back(k);
                    }
                if(j>0)
                    if(best[k-1]==1)
                    {
                        G[k].push_back(k-1);
                        G[k-1].push_back(k);
                    }
            }
        }
    }
    for(int i=0;i<=n*m;i++)
        best[i]=100000000;
    best[e]=0;
    l.push_back(e);
    bfs();
    ans=best[s];
  //  cout<<ans<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            k=m*i+j;
            if(best[k]<=ans)
                if(c[i][j]!='S'  && c[i][j]!='T' && c[i][j]!='E')
                {

                    int f=int(c[i][j]-'0');
             //       cout<<i<<" "<<j<<" "<<f<<" "<<c[i][j]<<" "<<k<<" "<<best[k]<<endl;
                    an+=f;
                }
        }
    cout<<an<<endl;
}