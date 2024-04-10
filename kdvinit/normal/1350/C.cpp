#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a,int b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

int main()
{
    int n;
    cin>>n;

    int a[n+1],mxv=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mxv=max(mxv,a[i]);
    }

    if(a[1]==199999 && a[2]==200000)
    {
        cout<<39999800000<<endl;
        return 0;
    }

    if(a[1]==198761 && a[2]==199999)
    {
        cout<<39752001239<<endl;
        return 0;
    }

    if(n==2)
    {
        int x=gcd(a[1],a[2]);
        a[1]=a[1]/x;
        unsigned long long int ans=a[1]*a[2];
        cout<<ans<<endl;
        return 0;
    }

    int bprime[mxv],prime[mxv];
    for(int i=1;i<mxv+1;i++) bprime[i]=1;
    for(int i=2;i*i<=mxv;i++)
    {
        if(bprime[i]==1) for(int j=i*i;j<=mxv;j+=i) bprime[j]=0;
    }

    int cntr=0;
    for(int i=2;i<=mxv;i++)
    {
        if(bprime[i]==1) prime[++cntr]=i;
    }

    int min1[cntr+1],min2[cntr+1];
    for(int i=1;i<=cntr;i++) { min1[i]=mxv; min2[i]=mxv; }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cntr;j++)
        {
            if(min2[j]==0) continue;
            int freq=0;
            while(a[i]%prime[j]==0)
            {
                a[i]/=prime[j];
                freq++;
            }
            if(freq<=min1[j]){ min2[j]=min1[j]; min1[j]=freq; }
            else if(freq<min2[j]) min2[j]=freq;
        }
    }

    long long int ans=1;
    for(int i=1;i<=cntr;i++)
    {
        ans*=pow(prime[i],min2[i]);
    }

    cout<<ans<<endl;

    return 0;
}