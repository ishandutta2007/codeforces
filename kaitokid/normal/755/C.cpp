#include <bits/stdc++.h>

using namespace std;


int parent [10007];

int pr(int x)
{
    if(parent[x]==x)return x;
    parent[x]=pr(parent[x]);
    return parent[x];
}



int main()
{
    ios::sync_with_stdio(0);
    for(int i=0; i<=10006; i++)
    {
    parent [i]=i;
    }
    int n,x;
    cin>>n;
    for(int i=1; i<=n; i++)
    {cin>>x;
    parent[pr(i)]=pr(x);}
    int ans=0;
       for(int i=1;i<=n;i++)
       {
           if(pr(i)==i){ans++;}
       }

       cout<<ans;
    return 0;
}