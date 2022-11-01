#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

    int ti[100001];
int main()
{
    int n;
    int k,q=0;
    cin>>n;
    int x;
    x=q;
    for (k=0;k<n;k++)
        
        
        cin>>ti[k];
    for (k=0;k<n;k++)
    {
        while (ti[k]%2==0) ti[k]=ti[k]/2;
        while (ti[k]%3==0) ti[k]=ti[k]/3;
    }

    for (k=1;k<n;k++)
        q=max(q,abs(ti[k]-ti[0]));


    if (q==0) cout<<"Yes"; else cout<<"No";
    return 0;
}