#include <bits/stdc++.h>

using namespace std;
int pr[200009],n,m,ans;

int pa(int x)
{
    if(pr[x]==x)return x;
    return pr[x]=pa(pr[x]);

}
void con(int a,int b)
{
    int u=pa(a),v=pa(b);
    if(u>v)pr[v]=u;
    else pr[u]=v;

}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)pr[i]=i;
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        con(x,y);
    }
    int i=1;
    while(i<=n)
    {
        int j=i+1;
        while(j<=pa(i))
        {
            if(pa(i)!=pa(j)){ans++;con(i,j);}
            j++;
        }
        i=j;
    }
    cout<<ans;
    return 0;
}