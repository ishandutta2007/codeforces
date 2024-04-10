#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n,k,ans=0,value;
        cin>>n>>k;
        int nd=2*k,a[n],f[2*k+1]={0},nf[2*k+1]={0};
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n/2;i++)
        {
            int sum;
            int x=min(a[i],a[n-1-i]);
            int y=max(a[i],a[n-1-i])+k;
            sum=a[i]+a[n-1-i];
            nf[x]++;
            nf[y+1]++;
            f[sum]++;
        }
        for(int i=1;i<k;i++)
        {
            nf[k+1-i]+=nf[k+1-i+1];
            nf[k+1+i]+=nf[k+i];
        }
        for(int i=2;i<=nd;i++)
        {
            ans=max(ans,(f[i]-nf[i]));
        }
        ans=n/2-ans;
        cout<<ans<<endl;
        t--;
    }
    return 0;
}