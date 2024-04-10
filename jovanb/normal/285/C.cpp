#include <bits/stdc++.h>

using namespace std;
long long niz[300005];
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,i;
    long long br=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
    }
    sort(niz,niz+n);
    for(i=0;i<n;i++){
        br+=abs(1+i-niz[i]);
    }
    cout<<br;
    return 0;
}