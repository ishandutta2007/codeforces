#include <bits/stdc++.h>
using namespace std;

long long zbir[300000],niz[300000],najbb[300000];
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long n,k,najb,naja,i,zmax=0;
    cin>>n>>k;
    cin>>niz[0];
    zbir[0]=niz[0];
    for(i=1;i<n;i++){
        cin>>niz[i];
        zbir[i]=zbir[i-1]+niz[i];
    }
    najb=n-k;
    zmax=0;
    naja=10000;
    for(i=n-2*k;i>=0;i--){
        if(zbir[i+2*k-1]-zbir[i+k-1]>=zbir[najb+k-1]-zbir[najb-1]){
            najb=i+k;
            najbb[i]=i+k;
        }
        else najbb[i]=najb;
        if(zmax<=zbir[najbb[i]+k-1]-zbir[najbb[i]-1]+zbir[i+k-1]-zbir[i-1]){
            zmax=zbir[najbb[i]+k-1]-zbir[najbb[i]-1]+zbir[i+k-1]-zbir[i-1];
            naja=i;
        }
    }
    cout<<naja+1<<" "<<najbb[naja]+1;
    return 0;
}