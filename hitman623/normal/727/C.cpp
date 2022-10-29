#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,a[5005],i,x;
    cin>>n;
    for(i=0;i<n-2;++i)
    {cout<<"? "<<i+1<<" "<<i+2<<endl;
    fflush(stdout);
    cin>>a[i];}
    cout<<"? "<<n-1<<" "<<n<<endl;
    fflush(stdout);
    cin>>a[i++];
    cout<<"? "<<n-!(n%2)<<" "<<1<<endl;
    fflush(stdout);
    cin>>a[i++];
    x=0;
    if(n%2==0)
    {
        for(i=0;i<n-2;++i)
        x+=pow(-1,i)*a[i];
        x+=pow(-1,i)*a[i+1];
    }
    else
    {
        for(i=0;i<n;++i)
        x+=pow(-1,i)*a[i];
    }
    x/=2;
    cout<<"! "<<x<<" ";
    for(i=0;i<n-1;++i)
    {
        cout<<a[i]-x<<" ";
        x=a[i]-x;
    }
    return 0;
}