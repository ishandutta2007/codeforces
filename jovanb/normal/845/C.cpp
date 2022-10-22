#include <bits/stdc++.h>

using namespace std;
long long niz[1000000];

bool cmp(long long a,long long b){
    if(abs(a)<abs(b))return true;
    if(abs(a)>abs(b))return false;
    if(a>b)return true;
    return false;
}
int main()
{
    long long i,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i]>>niz[n+i];
        niz[n+i]=0-niz[n+i];
    }
    n=2*n;
    sort(niz,niz+n,cmp);
    short signal=0;
    long long brojac=0;
    for(i=0;i<n;i++){
        if(niz[i]>=0)brojac++;
        if(brojac>2)signal=1;
        if(niz[i]<0)brojac--;

    }
    if(signal==1)cout<<"NO";
    else cout<<"YES";
    return 0;
}