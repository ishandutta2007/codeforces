#include <bits/stdc++.h>

using namespace std;
long long niz[100005];
int main()
{
    long long n,m=10000000000,ma=-10000000000,k,i;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>niz[i];
        m=min(m,niz[i]);
        ma=max(ma,niz[i]);

    }
    if(k==1)cout<<m;
    else if(k==2)cout<<max(niz[0],niz[n-1]);
    else cout<<ma;
    return 0;
}