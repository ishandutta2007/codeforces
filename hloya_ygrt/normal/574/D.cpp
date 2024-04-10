#include <iostream>
#include <algorithm>
using namespace std;

int n,i[100001];
int z[100001],k;
int _max=-1;




int main()
{

    cin>>n;
    for (k=0;k<n;k++)
    {
        cin>>i[k];
        z[k]=2e9;
    }
    z[0]=1;
    z[n-1]=1;
    
    for (k=1;k<n;k++)
         z[k]=min(z[k-1]+1,min(i[k],z[k]));
    
    for (k=n-2;k>=0;k--)
        z[k]=min(z[k+1]+1,min(i[k],z[k]));
    for (k=0;k<n;k++)
        _max=max(_max,z[k]);
    cout<<_max;
    return 0;
}