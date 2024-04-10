#include <bits/stdc++.h>

using namespace std;
int niz[100];
int main()
{
    int n,k,broj,br=0,i;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>niz[i];
    sort(niz,niz+n);
    broj=niz[n-k];
    for(i=0;i<n;i++)if(niz[i]>=broj && niz[i]>0)br++;
    cout<<br;
    return 0;
}