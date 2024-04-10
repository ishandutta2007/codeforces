// Hydro submission #6274d64dbda16328ffbb0236@1651824205783
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,s,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0;
        for(j=0;j<2*n;j++)
        {
            cin>>a;
            if(a%2)
            s++;
        }
        printf(s-n?"No\n":"Yes\n");
    }
    return 0;
}