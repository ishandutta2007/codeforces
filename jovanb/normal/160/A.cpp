#include <bits/stdc++.h>
using namespace std;
int niz[200];
int main(){
    int n,i,z=0,zb=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
        z+=niz[i];
    }
    z/=2;
    sort(niz,niz+n);
    for(i=n-1;i>=0;i--){
        zb+=niz[i];
        if(zb>z){cout<<n-i;return 0;}
    }
    cout<<n;
    return 0;
}