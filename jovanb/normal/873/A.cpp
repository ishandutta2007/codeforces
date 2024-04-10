#include <bits/stdc++.h>

using namespace std;
int niz[1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);


    int n,k,x,br=0,i;
    cin>>n>>k>>x;
    for(i=0;i<n;i++)cin>>niz[i];
    sort(niz,niz+n);
    for(i=0;i<n-k;i++)br+=niz[i];
    br+=k*x;
    cout<<br;
    return 0;
}