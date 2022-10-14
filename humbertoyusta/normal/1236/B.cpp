#include<bits/stdc++.h>
#define maxn 100010
#define mod 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

long long a, b;

long long qpow(long long b,int e){
    if( e == 0 ) return 1ll;
    if( e & 1 ) return qpow( b , e - 1 ) * b % mod;
    long long p = qpow( b , e >> 1 );
    return p * p % mod;
}

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    cin >> a >> b;

    cout << qpow( qpow( 2 , b ) - 1 , a ) << '\n';

    return 0;
}