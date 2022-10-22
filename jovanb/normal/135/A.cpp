#include <bits/stdc++.h>
using namespace std;

long long niz[1000000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
    }
    sort(niz,niz+n);
    if(niz[n-1]!=1)niz[n-1]=1;
    else niz[n-1]=2;
    sort(niz,niz+n);
    for(i=0;i<n;i++)cout<<niz[i]<<" ";
    return 0;
}