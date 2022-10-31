// Hydro submission #62972b73b0c5e75beb158566@1654074228005
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,l,r,s,k,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>l>>r>>k;
        if(l-r)
        printf(r-l+1>(r-l+1>>1)+k+(l%2==0&&r%2==0)?"NO\n":"YES\n");
        else printf(l>1?"YES\n":"NO\n");
    }
    return 0;
}