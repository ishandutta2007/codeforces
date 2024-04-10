#include <bits/stdc++.h>

using namespace std;

bool isprime(long long x){
    for(long long i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long n;
    cin>>n;
    if(isprime(n)){cout<<1;return 0;}
    if(n%2==0)cout<<2;
    else if (isprime(n-2))cout<<2;
    else cout<<3;
    return 0;
}