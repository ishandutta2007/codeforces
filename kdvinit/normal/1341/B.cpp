#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n,k;
        cin>>n>>k;
        int a[n+1]={0},P[n+1]={0},MP[n+1]={0},p=0,l=1,ans;
        for(int i=1;i<n+1;i++) cin>>a[i];
        for(int i=2;i<n;i++)
        {
            if(a[i]>a[i+1] && a[i]>a[i-1])
            {
                P[i]=1;
                if(i<k) MP[1]++;
            }
        }
        for(int i=2;i<=n-k+1;i++)
        {
            int cntr=0;
            if(P[i+k-2]==1) cntr++;
            if(P[i]==1) cntr--;
            MP[i]=MP[i-1] + cntr;
        }
        ans=MP[1];
        for(int i=2;i<=n-k+1;i++)
        {
            if (MP[i]>ans)
            {
                ans=MP[i];
                l=i;
            }
        }
        cout<<ans+1<<" "<<l<<endl;

        t--;
    }
    return 0;
}