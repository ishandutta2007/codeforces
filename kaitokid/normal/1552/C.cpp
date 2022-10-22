#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,x[409],y[409];
int num[1000];
bool cont(int u,int v)
{
    if(x[u]>x[v])swap(u,v);
    if(x[v]>y[u])return false;
    if(y[u]>y[v])return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<=2*n;i++)num[i]=0;
        for(int i=0;i<k;i++)
        {cin>>x[i]>>y[i];num[x[i]]++,num[y[i]]++;
        if(x[i]>y[i])swap(x[i],y[i]);
        }
        vector<int>u;
        for(int i=1;i<=2*n;i++)
            if(num[i]==0)u.push_back(i);
        int r=k;
        for(int i=0;i<n-k;i++)
        {
            x[r]=u[i];
            y[r]=u[i+n-k];

            r++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            if(cont(i,j))ans++;

            cout<<ans<<endl;



         }
    return 0;
}