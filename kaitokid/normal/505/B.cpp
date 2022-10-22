#include <bits/stdc++.h>

using namespace std;


int parent [107][107];

int pr(int x,int y)
{
    if(parent[x][y]==x)return x;
    parent[x][y]=pr(parent[x][y],y);
    return parent[x][y];
}



int main()
{
    ios::sync_with_stdio(0);
    for(int i=0; i<=100; i++)
    {for(int j=0;j<=100;j++){
        parent[i][j]=i;

    }}
    int n,m,x,y,z;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y>>z;

        int g=pr(x,z),f=pr(y,z);
        if(g!=f)
        {
            parent[g][z]=f;

        }
    }
int k;

    cin>>k;
  for(int i=0;i<k;i++)
  {int ans=0;
      cin>>x>>y;
      for(int i=0;i<=100;i++)
      {
          if(pr(x,i)==pr(y,i)){ans++;}
      }
      cout<<ans<<endl;
  }
    return 0;
}