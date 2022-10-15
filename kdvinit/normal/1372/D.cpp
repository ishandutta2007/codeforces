/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n,m;
    cin>>n;
    m=(n+1)/2;

    long long int a[2*n+1]={0},sum=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        long long int x,y=(i+1)/2;
        cin>>x;

        if(i%2==0) a[m+y]=x;
        else { a[y]=x; a[n+y]=x; sum+=x; }
    }

    ans=sum;
    for(int i=1;i<=n;i++)
    {
        sum+=(a[m+i]-a[i]);
        ans=max(ans,sum);
    }
    
    cout<<ans<<endl;
    return 0;
}