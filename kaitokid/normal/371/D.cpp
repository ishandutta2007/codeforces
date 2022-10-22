#include <bits/stdc++.h>

using namespace std;
    int n;
 int parent[200002],a[200002],b[200002];
 int pr(int x)
 {
     if(parent[x]==x){return x;}
     parent[x]=pr(parent[x]);
     return parent [x];
 }
 void go(int x)
 {if(b[x]>=a[x]&&x<n){parent[x]=pr(x+1);}
 if(x==n){b[x]=a[x];return;}
b[pr(x)]+=b[x]-a[x];
b[x]=a[x];
if(b[pr(x)]>=a[pr(x)])go(pr (x));
 }

int main()
{ios::sync_with_stdio(0);


    cin>>n;
    for(int i=1;i<=n;i++)
    {cin>>a[i];
    parent[i]=i;

    }
    int m,x,y,z;
    cin>>m;
    for(int i=0;i<m;i++)
    {cin>>x>>y;
    if(x==2){cout<<b[y]<<endl;continue;}
    if(x==1){cin>>z;b[y]+=z;if(b[y]>=a[y]){go(y);}}
    }
    return 0;
}