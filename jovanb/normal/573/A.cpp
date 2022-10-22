#include <bits/stdc++.h>
using namespace std;

long long niz[1000000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long n,gcd=0,x,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
        if(gcd==0)gcd=niz[i];
        gcd=__gcd(gcd,niz[i]);
    }
    for(i=0;i<n;i++){
        x=niz[i]/gcd;
        while(x%2==0)x/=2;
        while(x%3==0)x/=3;
        if(x!=1){cout<<"No";return 0;}
    }
    cout<<"Yes";
    return 0;
}