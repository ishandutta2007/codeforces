// Hydro submission #6274ce28bda16328ffbafbcd@1651822120727
#include<bits/stdc++.h>
using namespace std;
int a[100000],s;
int main()
{
    int n,q,t,x,k,i;
    cin>>n>>q;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]) s++; 
    }
    for(i=0;i<q;i++)
    {
        cin>>t;
        if(t==1)
        {
            cin>>x;
            (a[x-1]^=1)?s++:s--;
        }
        else
        {
            cin>>k;
            printf(s<k?"0\n":"1\n");
        }
    }
    return 0;
}