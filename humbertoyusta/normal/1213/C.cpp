#include<bits/stdc++.h>
#define maxn 150010
#define inf 1000000007
#define ii pair<int,int>
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;

ll tc, mk[10];
ll a, b, s, res, curr;
vector<ll> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while( tc-- ){

        fill( mk , mk + 10 , 0 );

        cin >> a >> b;

        s = 0ll;
        v.clear();
        ll d = b % 10ll;
        while( !mk[d] ){
            mk[d] = 1ll;
            v.push_back(d);
            s += d;
            d = ( d + b ) % 10ll;
        }

        d = b % 10ll;
        curr = 0ll;
        for(ll i=b; i<=( a % ( (ll)v.size() * b ) ); i+=b){
            curr += d;
            d = ( d + b ) % 10ll;
        }

        cout << ( a / ( (ll)v.size() * b ) ) * s + curr << '\n';
    }

    return 0;
}