#include <bits/stdc++.h>
using namespace std;

long long postoji[10000000];
long long niz[10000000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long n,x,i,br=0;
    cin>>n>>x;
    for(i=0;i<n;i++){
        cin>>niz[i];
        postoji[niz[i]]++;
    }
    for(i=0;i<n;i++){
        br+=postoji[niz[i] ^ x];
        if(x==0)br--;
    }
    cout<<br/2;
    return 0;
    return 0;
}