#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
bool ch(int x)
{
    int q=k*x;
    if(q<n)return false;
    q-=n;
    if(q%2)return false;
    q/=2;
    int r=(q+n-1)/n;
    if(2*r+1>x)return false;
    return true;

}
int h[509];
vector<int>rs[509];
void go(int x)
{
    int q=x*k-n;
    for(int i=1;i<=n;i++)h[i]=1;
    int u=1;
    while(q>0)
    {
        h[u]+=2;
        q-=2;
        u++;
        if(u==n+1)u=1;
    }
    u=1;
    for(int i=1;i<=n;i++)
    {
        while(h[i]){rs[u].push_back(i);h[i]--;u++;if(u==x+1)u=1;}
    }
    int ans=0;
    for(int i=1;i<=x;i++)
    {
        cout<<"? ";
        for(int j=0;j<rs[i].size();j++)cout<<rs[i][j]<<" ";
        cout<<endl;
        fflush(stdout);
        int z;
        cin>>z;
        ans^=z;
    }
    cout<<"! "<<ans<<endl;
    fflush(stdout);
}
int main()
{
        cin>>n>>k;
        for(int i=1;i<=500;i++)
        {
            if(ch(i)){go(i);return 0;}
        }
        cout<<-1<<endl;
        fflush(stdout);

    return 0;
}