#include <bits/stdc++.h>
using namespace std;

long niz[10000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,i;
    cin>>n;
    niz[0]=0;
    for(i=1;i<=n;i++)cin>>niz[i];
    sort(niz+1,niz+1+n);
    for(i=1;i<=n;i++){
        if(niz[i]>niz[i-1]+1){cout<<niz[i-1]+1;return 0;}
    }
    cout<<niz[n]+1;
    return 0;
}