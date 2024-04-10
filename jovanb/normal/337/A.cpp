#include <bits/stdc++.h>

using namespace std;
int niz[55];
int main()
{
    int n,k,i,mindif=10000;
    cin>>k>>n;
    for(i=0;i<n;i++)cin>>niz[i];
    sort(niz,niz+n);
    for(i=0;i<=n-k;i++){
       mindif=min(mindif,niz[i+k-1]-niz[i]);
    }
    cout<<mindif;
    return 0;
}