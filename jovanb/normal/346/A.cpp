#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,gcd,maxi,x,i;
    cin>>n;
    cin>>x;
    maxi=x;
    gcd=x;
    for(i=1;i<n;i++){
        cin>>x;
        maxi=max(maxi,x);
        gcd=__gcd(gcd,x);
    }
    cout<<(((maxi/gcd)-n)%2==1 ? "Alice" : "Bob");
    return 0;
}