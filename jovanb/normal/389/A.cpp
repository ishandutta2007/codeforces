#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,gcd,i,x;
    cin>>n;
    cin>>gcd;
    for(i=1;i<n;i++){
        cin>>x;
        gcd=__gcd(gcd,x);
    }
    cout<<gcd*n;
    return 0;
}