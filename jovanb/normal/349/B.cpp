#include <bits/stdc++.h>
using namespace std;

int niz1[1000000];
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long v,niz[10],ind=0,i,r=0,j;
    niz[0]=1000000;
    cin>>v;
    for(i=1;i<=9;i++){
        cin>>niz[i];
        if(niz[i]<=niz[ind])ind=i;
    }
    if(v<niz[ind]){cout<<-1;return 0;}
    while(v>=niz[ind]){
        niz1[r]=ind;
        v-=niz[ind];
        r++;
    }
    for(i=0;i<r;i++){
        for(j=9;j>=ind;j--){
            if(niz[j]<=v+niz[ind]){
                v+=niz[ind]-niz[j];
                niz1[i]=j;
                break;
            }
        }
    }
    for(i=0;i<r;i++)cout<<niz1[i];
    return 0;
}