#include <bits/stdc++.h>
using namespace std;
long long niz[100000];
int main(){
    long n,i;
    long long a,b,maxi,v=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        v+=a;
    }
    for(i=0;i<n;i++){
        cin>>niz[i];
    }
    sort(niz,niz+n);
    if(niz[n-1]+niz[n-2]>=v)cout<<"YES";
    else cout<<"NO";
    return 0;
}