#include <bits/stdc++.h>
using namespace std;

long long niz[5];

int main(){
    long long i;
    for(i=0;i<3;i++)cin>>niz[i];
    sort(niz,niz+3);
    if((niz[0]+niz[1])*2<=niz[2])cout<<niz[0]+niz[1];
    else cout<<(niz[0]+niz[1]+niz[2])/3;
}