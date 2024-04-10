#include <bits/stdc++.h>

using namespace std;
long niz[5];
int main()
{
    long n,i,x,r;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        niz[x]++;
    }
    x=niz[4];
    x+=min(niz[3],niz[1]);
    r=niz[3];
    niz[3]-=min(niz[3],niz[1]);
    niz[1]-=min(r,niz[1]);
    x+=niz[3];
    x+=niz[2]/2;
    niz[2]%=2;
    if(niz[2]==1){
        x++;
        niz[1]-=min(long(2),niz[1]);
    }
    if(niz[1]%4==0)x+=niz[1]/4;
    else x+=niz[1]/4+1;
    cout<<x;
    return 0;
}