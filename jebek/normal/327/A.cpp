#include <iostream>
#include<algorithm>

using namespace std;

int a[110],b[110],c[110],MAX=-10000000,n;

int main()
{
    cin>>n;
    cin>>a[0];
    b[0]=-2*a[0]+1;
    c[0]=a[0];
    MAX=b[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        b[i]=-2*a[i]+1+b[i-1];
        c[i]=c[i-1]+a[i];
        MAX=max(MAX,b[i]);
        for(int j=0;j<i;j++)
        {
            MAX=max(MAX,b[i]-b[j]);
        }
    }
    cout<<MAX+c[n-1];
}