#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,l,r,m,mcl=0,mcu=1000000009,mdl=0,mdu=1000000009,i;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>l>>r;
        if(r<mcu) mcu=r;
        if(l>mcl) mcl=l;
    }
    cin>>m;
    for(i=0;i<m;++i)
    {
        cin>>l>>r;
        if(r<mdu) mdu=r;
        if(l>mdl) mdl=l;
    }
    cout<<max(max(mdl-mcu,mcl-mdu),(long)0);
    return 0;
}