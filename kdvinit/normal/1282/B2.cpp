/*
2
5 11 2
2 4 3 5 7
5 2 3
10 1 3 9 2

*/

#include <iostream>
#include <algorithm>
using namespace std;

void show(long long int a[],int strt,long long int nd)
{
    for(int i=strt;i<=nd;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,p,k;
        cin>>n>>p>>k;
        long long int a[n+1],ans,sum[n+1]={0};
        for(int i=1;i<n+1;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        //show(a,1,n);
        sum[1]=a[1];
        for(int i=2;i<n+1;i++)
        {
            if(i<=k) sum[i]=a[i]+sum[i-1];
            //cout<<i<<" - "<<sum[i]<<" "<<a[k]<<endl;
            if(i<=k) { a[i]=min(sum[i],a[k]); continue; }
            if(i%k==0) { a[i]+=a[i-k]; continue; }
            int y=i;
            y=y-y%k;
            sum[i]=a[i]+sum[i-k];
            if(y+k>n) a[i]=sum[i];
            else a[i]=min(sum[i],a[y]+a[y+k]);
        }
        //show(a,1,n);
        //show(sum,1,n);
        int i;
        for(i=1;i<n+1;i++)
        {
            if(a[i]>p)break;
        }
        int x=i-1;
        cout<<x<<endl;
    }
    return 0;
}