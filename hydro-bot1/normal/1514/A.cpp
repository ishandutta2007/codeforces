// Hydro submission #6274cf69bda16328ffbafd82@1651822443758
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,i,j;
    cin>>t;bool f;
    for(i=0;i<t;i++)
    {
        cin>>n;
        f=false;
        for(j=0;j<n;j++)
        {
            cin>>a;
            if(sqrt(a)-int(sqrt(a)))
            f=true;
        }
        printf(f?"YES\n":"NO\n");
    }
    return 0;
}