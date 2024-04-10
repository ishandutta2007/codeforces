#include<bits/stdc++.h>
#define db(x) cerr<<#x<<": "<<(x)<<'\n'
using namespace std;

const long long mod=1e9+7;
long long a,b,c,d;

long long pot(long long bas,long long exp){

    if(exp==0LL) return 1LL;

    if(exp%2LL==1) return (bas*pot(bas,exp-1))%mod;

    long long p = pot(bas,exp/2);

    return (p*p)%mod;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    if( a == 0 ){ cout << 0 <<'\n'; return 0; }

    a%=mod;

    b++;

    c=(a*pot(2,b))%mod;

    d=pot(2,b-1)-1;

    cout << ( c + mod - d ) % mod << '\n';

return 0;
}