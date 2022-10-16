#include <iostream>

using namespace std;

int a[52], n, t;

int main()
{
    char k;
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {    
    cin>>k;
        if(k=='B') a[i]=1;
            else a[i]=2;
    }
    
    for(int i=1;i<=t;i++)
        for(int ii=1;ii<n;ii++)
        {
            if(a[ii]==1 && a[ii+1]==2) a[ii]=2, a[ii+1]=1, ii++;    
    
        }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)cout<<'B';
        else cout<<'G';
}
}