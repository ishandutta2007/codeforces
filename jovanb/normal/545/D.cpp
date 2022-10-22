#include <bits/stdc++.h>

using namespace std;
long long niz[long(1e5+1)];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long i,n;
    long long zb=0,br;
    cin>>n;
    for(i=0;i<n;i++)cin>>niz[i];
    sort(niz,niz+n);
    zb=niz[0];
    br=n;
    for(i=1;i<n;i++){
        if(niz[i]<zb)br--;
        else zb+=niz[i];
    }
    cout<<br;
    return 0;
}