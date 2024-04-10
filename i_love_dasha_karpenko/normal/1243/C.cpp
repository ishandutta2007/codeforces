#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define fi first
#define sc second
#define pb push_back
#define endl '\n'
#define x1 dsfdsfdsfewewer
#define y1 fdgretdfdsfgddsf
const ll DIM = 2*(10e4)+7;
const ll INF = 10e16;
const ll MOD = (10e9)+7;
const ll _MAX = (10e8)+7;
/*                       */

ll n;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    ll sq = sqrt(n);
    ll mi = n;
    for(ll i = 2;i<=sq;i++){
        if (n%i==0){
            mi = __gcd(mi,i);
            mi = __gcd(mi,n/i);
        }

    }
    cout<<mi<<endl;
    return 0;
}