#include <iostream>
using namespace std;

long long int tmpans(long long int a[],int strt,int nd,int k)
{
    long long int mx=0,mn=1000000000;
    for(int i=0;i<=k;i++)
    {
        mx=max(a[strt+i],a[nd+i-k]);
        mn=min(mn,mx);
    }
    return mn;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        long long int a[n+1],ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(m-1<k) k=m-1;
        for(int i=0;i<=k;i++)
        {
            long long int temp=tmpans(a,1+i,n-k+i,m-k-1);
            ans=max(ans,temp);
        }
        cout<<ans<<endl;
    }
    return 0;
}