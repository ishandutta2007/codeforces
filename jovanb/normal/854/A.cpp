#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,n;
    cin>>n;
    for(i=n-1;i>=1;i--){
        if(__gcd(i,n-i)==1 && i<n-i){cout<<i<<" "<<n-i;return 0;}
    }
    return 0;
}