#include <bits/stdc++.h>

using namespace std;
int niz[2005];
int main()
{
    long br=0,n,k,i;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>niz[i];
    sort(niz,niz+n);
    reverse(niz,niz+n);
    for(i=0;i<n;i+=k){
        br+=(niz[i]-1)*2;
    }
    cout<<br;
    return 0;
}