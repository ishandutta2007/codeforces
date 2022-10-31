#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 fdgfdgf
#define y1 fdhfdgfdg
#define endl '\n'
const ll DIM = 300+7;
ll Sum(ll n){
    ll ret = 0;
    while(n){
        ret+=n%10;
        n/=10;
    }
    return ret;
}
ll Ch(ll n){
    return __gcd(n,Sum(n))!=1ll;
}
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        while(!Ch(n))++n;
        cout<<n<<endl;
    }
    return 0;
}