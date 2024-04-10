#include <bits/stdc++.h>

using namespace std;
long long niz[1000000];
map <long long, long long> br;
long long brovi[31];
int main()
{
    long long n,i,prn=0,bro=0,x,j;
    cin>>n;
    brovi[0]=1;
    for(i=1;i<=30;i++){
        brovi[i]=brovi[i-1]*2;
    }
    for(i=0;i<n;i++){
        cin>>x;
        br[x]++;
        if(br[x]<=1){
            niz[prn]=x;
            prn++;
        }
    }
    n=prn;
    sort(niz,niz+n);
    for(i=0;i<n;i++){
        for(j=0;j<=30;j++){
            x=brovi[j]-niz[i];
            if(x==niz[i] && br[niz[i]]>1){
                bro+=(br[niz[i]]*(br[niz[i]]-1))/2;
            }
            if(x>niz[i]){
                bro+=(br[niz[i]]*br[x]);
            }
        }
    }
    cout<<bro;
    return 0;
}