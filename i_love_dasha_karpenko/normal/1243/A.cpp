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

ll t,A[DIM];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //cout<<_MAX<<endl;
    cin>>t;
    forn(query,t){
       ll n; cin>>n;
       forn(i,n)cin>>A[i];
       sort(A+1,A+1+n);
       ll res = 0;
       for(ll i = n;i>0;i--){
        res = max(res,min(n-i+1,A[i]));
        //cout<<res<<endl;
       }
       cout<<res<<endl;
    }
    return 0;
}