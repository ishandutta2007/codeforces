#include <iostream>
#include<algorithm>

using namespace std;

int n;
long long a[10000];

long long dp(int l,int r,long long k)
{
    if(l>=r)
        return 0;
    if(l+1>=r)
        return min(1LL,max(0LL,a[l]-k));
    long long MIN=10000000000000,ind;
    for(int i=l;i<r;i++)
    {
        if(a[i]<MIN)
        {
            MIN=a[i];
            ind=i;
        }
    }
    //cout<<l<<" "<<r<<" "<<k<<" "<<min((r-l)*1LL,MIN-k+dp(l,ind,MIN)+dp(ind+1,r,MIN))<<endl;
    return min((r-l)*1LL,MIN-k+dp(l,ind,MIN)+dp(ind+1,r,MIN));
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<dp(0,n,0)<<endl;
}