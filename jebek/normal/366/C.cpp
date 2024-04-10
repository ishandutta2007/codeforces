#include <iostream>

using namespace std;

const int INF=-1000000000;

int n,a[200],b[200];
long long d[110][120000];

int dp(int x,int k)
{
    if(d[x][k+10000]!=-1) return d[x][k+10000];
    d[x][k+10000]=INF;
    if(k==0)
        d[x][k+10000]=0;
    if(x>=n)
        return d[x][k+10000];
    d[x][k+10000]=max(dp(x+1,k),dp(x+1,k+b[x])+a[x]);
   // cout<<x<<" "<<k<<" "<<a[x]<<" "<<b[x]<<" "<<d[x][k+10000]<<endl;
    return d[x][k+10000];
}

int main()
{
    int k;
    cin>>n>>k;
    for(int i=0;i<110;i++)
        for(int j=0;j<120000;j++)
            d[i][j]=-1;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        b[i]*=k;
        b[i]-=a[i];
    }
    if(dp(0,0)<=0)
        cout<<-1<<endl;
    else
        cout<<dp(0,0);
}