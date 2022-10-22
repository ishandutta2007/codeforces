#include <bits/stdc++.h>

using namespace std;
long long niz[100005];
int main()
{
    long n,i,maxi=0,tren=0;
    cin>>n;
    cin>>niz[0];
    tren=1;
    maxi=1;
    for(i=1;i<n;i++){
        cin>>niz[i];
        if(niz[i]<niz[i-1]){
            maxi=max(maxi,tren);
            tren=0;
        }
        tren++;
        maxi=max(tren,maxi);
    }
    cout<<maxi;
    return 0;
}